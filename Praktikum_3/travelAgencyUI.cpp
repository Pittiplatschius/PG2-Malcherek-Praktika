#include "travelAgencyUI.h"
#include "qobjectdefs.h"
#include "ui_travelAgencyUI.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"

#include <QFileDialog>
#include <QInputDialog>
#include <QListWidget>
#include <QMessageBox>
#include <typeinfo>
#include <QTableWidget>

TravelAgencyUI::TravelAgencyUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tA(new TravelAgency)
{
    ui->setupUi(this);
    ui->tableWidget->show();
    ui->tableWidget->setColumnWidth(0, 30);
    ui->tableWidget->setColumnWidth(0, 50);
    ui->tableWidget->setColumnWidth(0, 50);
    ui->tableWidget_2->show();
    ui->tableWidget_2->setColumnWidth(0, 30);
    ui->tableWidget_2->setColumnWidth(0, 50);
    ui->tableWidget_2->setColumnWidth(0, 50);
    ui->tableWidget_2->setColumnWidth(0, 50);
    connect(ui->actionEinlesen, SIGNAL(triggered(bool)),this, SLOT(pushButton_Einlesen()));
    connect(ui->actionBuchungSuchen, SIGNAL(triggered(bool)), this, SLOT(pushButton_BuchungSuchen()));
    connect(ui->actionAlle_anzeigen, SIGNAL(triggered(bool)), this, SLOT(pushButton_Alle_anzeigen()));
    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(doubleClickedListWidget()));
    connect(ui->actionExportieren, SIGNAL(triggered(bool)), this, SLOT(pushBotton_Exportieren()));
    connect(ui->actionListe_sortieren, SIGNAL(triggered(bool)), this, SLOT(pushButton_Liste_sortieren()));
    connect(ui->actionKundeSuchen, SIGNAL(triggered(bool)), this, SLOT(pushButton_KundeSuchen()));

}

TravelAgencyUI::~TravelAgencyUI()
{
    std::cout << "Fenster wurde geschlossen!" << std::endl;
    delete ui;
}

void TravelAgencyUI::pushButton_Einlesen()
{
    bool fileRead = false;
    QString qstr;
    int numberOfLine = 0;

    do {
        try {
            QString filename = QFileDialog::getOpenFileName(
                        this,
                        tr("Open File"),
                        "C://",
                        "Text File (*.txt)"
                        );

            if(numberOfLine == 0) {
                tA->readFile(filename);
            } else {
                tA->readFile(filename, numberOfLine);
            }
            QMessageBox::information(this, tr("Datei erfolgreich eingelesen"), tA->bookedMessage());
            fileRead = true;
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            qstr = QString::fromStdString(e.what());
            std::string ewhat = e.what();

            QMessageBox reply;
            reply.setText(qstr);
            reply.setWindowTitle("Fehler beim Einlesen der Buchung");
            reply.setStandardButtons(QMessageBox::Retry | QMessageBox::Discard | QMessageBox::Cancel);
            reply.setDefaultButton(QMessageBox::No);
            reply.setDetailedText("Retry - Datei wurde korrigiert und soll neu eingelesen werden\n"
                                  "Don't save - Eingelesenen Buchungen der aktuellen Datei löschen\n"
                                  "Cancel - Bereits eingelesenen Buchungen der Datei stehenzulassen und Dialog verlassen.");
            int rep = reply.exec();

            switch (rep) {
            case QMessageBox::Retry: {
                std::size_t zwischenSize = ewhat.find(":");
                std::string zwischenSpeicher = ewhat.substr(zwischenSize+2, (ewhat.size() - zwischenSize));
                numberOfLine = stoi(zwischenSpeicher);
                break;
            }
            case QMessageBox::Discard: {
                tA->deleteBookings();
                return;
            }
            case QMessageBox::No: {
                break;
            }
            case QMessageBox::Cancel: {
                return;
            }
            default:
                std::cout << "Nicht definierter Fehler" << std::endl;
                return;
            }

            fileRead = false;
        }

    }while(fileRead != true);
}

void TravelAgencyUI::pushButton_BuchungSuchen()
{
    int id;

    if(!tA->getAllBookingsVec().empty()) {
        QString text = QInputDialog::getText(this, "Buchung suchen", "Buchungs-ID:");
        id = text.toInt();

        for(auto &k : tA->getAllBookingsVec()) {
            if(k->getBookingID() == id) {
                ui->listWidget->clear();
                ui->listWidget->addItem(k->showDetails());
                listDetails(id);
                return;
            } else {
                QMessageBox::information(this, tr("Fehler beim suchen einer Buchung"), "Es existiert keine Buchung mit dieser ID");
            }
        }
    } else {
        QMessageBox::information(this, tr("Fehler beim suchen einer Buchung"), "Die Buchungsliste enthält keine Einträge");
    }
}

void TravelAgencyUI::pushBotton_Exportieren()
{
    if(!tA->getAllBookingsVec().empty()) {
        QString filename = QFileDialog::getSaveFileName(
                    this,
                    tr("Save File"),
                    "C://",
                    "Json File (*.json)"
                    );

        tA->exportJsonFile(filename);
    } else {
        QMessageBox::information(this, tr("Fehler beim Exportieren"), "Die Buchungsliste enthält keine Einträge");
    }
}

void TravelAgencyUI::pushButton_Liste_sortieren()
{
    //nach was soll sortiert werden? Aktuell nur nach ID

    if(!tA->getAllBookingsVec().empty()) {
        tA->sortBookings();
        pushButton_Alle_anzeigen();
    } else {
        QMessageBox::information(this, tr("Fehler beim sortieren der Liste"), "Die Buchungsliste enthält keine Einträge");
    }
}

void TravelAgencyUI::pushButton_Alle_anzeigen()
{
    ui->listWidget->clear();

    if(!tA->getAllBookingsVec().empty()) {
        for(size_t i = 0; i < tA->getAllBookingsVec().size(); i++) {
            ui->listWidget->addItem(tA->getAllBookingsVec().at(i)->showDetails());
        }
    } else {
        QMessageBox::information(this, tr("Fehler beim auflisten der Buchungen"), "Die Buchungsliste enthält keine Einträge");
    }
}

void TravelAgencyUI::pushButton_KundeSuchen()
{
    int customerID;
    QString qstr;
    QString text = QInputDialog::getText(this, "Kunde suchen", "Kunden-ID:");
    customerID = text.toInt();

    Customer *customer = tA->findCustomer(customerID);

    if(!tA->getAllCustomerVec().empty() || customer != nullptr) {
        ui->lineEdit_12->setText(QString::fromStdString(customer->getName()));

        if(!customer->getTravelListVec().empty()) {

            for(auto &k : customer->getTravelListVec()) {
                int rowCount = ui->tableWidget->rowCount();
                ui->tableWidget->setRowCount(rowCount + 1);

                qstr = QString::fromStdString(std::to_string(k->getTravelID()));

                for(auto &j : k->getTravelBookingsVec()) {
                    QString qStringFromDate = QString::fromStdString(j->getFromDate());
                    QString qStringToDate = QString::fromStdString(j->getToDate());

                    QTableWidgetItem *items [] = {
                        new QTableWidgetItem(qstr.arg(rowCount)),
                        new QTableWidgetItem(qStringFromDate.arg(rowCount)),
                        new QTableWidgetItem(qStringToDate.arg(rowCount))
                    };

                    const size_t count = sizeof(items) / sizeof(QTableWidgetItem *);
                    for(size_t column = 0; column < count; column++) {
                        ui->tableWidget->setItem(rowCount, column, items[column]);
                    }
                }
            }

        } else {
            std::cout << "Liste der Reisen des Kunden ist leer" << std::endl;
            return;
        }
    } else {
        QMessageBox::information(this, tr("Fehler beim suchen eines Kundens"), "Die Buchungsliste enthält keinen Kunden mit dieser ID");
        return;
    }
}

void TravelAgencyUI::doubleClickedListWidget() const
{
    std::string str;
    int id;

    QString qstr = ui->listWidget->currentItem()->text();
    QString subString = qstr.mid(4, 2);

    id = std::stoi(subString.toStdString());

    listDetails(id);
}

void TravelAgencyUI::listDetails(const int &id) const
{

    for(auto &k : tA->getAllBookingsVec()) {
        if(k->getBookingID() == id) {

            switch (k->getBookingType()) {
            case Flight: {
                FlightBooking* flight = dynamic_cast<FlightBooking*>(k);
                ui->lineEdit->setText(QString::number(id));
                ui->lineEdit_2->setText(QString::fromStdString(flight->getFromDestination()));
                ui->lineEdit_3->setText(QString::fromStdString(flight->getToDestination()));
                ui->dateEdit->setDate(k->getQFromDate());
                ui->lineEdit_4->setText(QString::fromStdString(flight->getAirline()));
                ui->doubleSpinBox->setValue(flight->getPrice());
                break;
            }
            case Rent: {
                RentalCarReservation* rentalCar = dynamic_cast<RentalCarReservation*>(k);
                ui->lineEdit_5->setText(QString::number(id));
                ui->lineEdit_6->setText(QString::fromStdString(rentalCar->getCompany()));
                ui->dateEdit_2->setDate(k->getQFromDate());
                ui->lineEdit_7->setText(QString::fromStdString(rentalCar->getPickupLocation()));
                ui->dateEdit_3->setDate(k->getQToDate());
                ui->lineEdit_8->setText(QString::fromStdString(rentalCar->getReturnLocation()));
                ui->doubleSpinBox_2->setValue(rentalCar->getPrice());
                break;
            }
            case Hotel: {
                HotelBooking* hotel = dynamic_cast<HotelBooking*>(k);
                ui->lineEdit_9->setText(QString::number(id));
                ui->lineEdit_10->setText(QString::fromStdString(hotel->getHotel()));
                ui->lineEdit_11->setText(QString::fromStdString(hotel->getTown()));
                ui->dateEdit_4->setDate(k->getQToDate());
                ui->dateEdit_5->setDate(k->getQToDate());
                ui->doubleSpinBox_3->setValue(hotel->getPrice());
                break;
            }
            default:
                break;
            }
            return;
        }
    }
}
