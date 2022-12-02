#include "mainwindow.h"
#include "qobjectdefs.h"
#include "ui_mainwindow.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"
#include <QFileDialog>
#include <QInputDialog>
#include <QListWidget>
#include <QMessageBox>
#include <typeinfo>
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tA(new TravelAgency)
{
    ui->setupUi(this);
    connect(ui->actionEinlesen, SIGNAL(triggered(bool)),this, SLOT(pushButton_Einlesen()));
    connect(ui->actionAuswaehlen, SIGNAL(triggered(bool)), this, SLOT(pushButton_Auswaehlen()));
    connect(ui->actionAlle_anzeigen, SIGNAL(triggered(bool)), this, SLOT(pushButton_Alle_anzeigen()));
    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(doubleClickedListWidget()));
    connect(ui->actionExportieren, SIGNAL(triggered(bool)), this, SLOT(pushBotton_Exportieren()));
}

MainWindow::~MainWindow()
{
    std::cout << "Fenster wurde geschlossen!" << std::endl;
    delete ui;
}

void MainWindow::pushButton_Einlesen()
{
    bool fileRead = false;
    QString qstr;

    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "Text File (*.txt)"
                );

    do {
        try {
            tA->readTextFile(filename);
            fileRead = true;
            QMessageBox::information(this, tr("Datei erfolgreich eingelesen"), tA->bookedMessage());
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            qstr = QString::fromStdString(e.what());

            QMessageBox reply;
            reply.setText(qstr);
            reply.setWindowTitle("Fehler beim Einlesen der Buchung");
            reply.setStandardButtons(QMessageBox::Retry | QMessageBox::Discard | QMessageBox::Cancel);
            reply.setDefaultButton(QMessageBox::No);
            reply.setDetailedText("Wenn Sie die Datei bereits korrigiert haben, wählen Sie 'Wiederholen'."
                                  "Wählen Sie 'Verwerfen', um alle Buchungen zu löschen und 'Abbrechen' um die vorhandnen Buchungen stehenzulassen und dieses Diealog zu verlassen.");
            int rep = reply.exec();

            //Hier fehlt der Button Details ausblenden statt No.
            // Ebenso Fehlen die Details selbst und die Buttons müssen Deutsch sein.
            //Bisher noch keine Ahnung wie das geht.

            switch (rep) {
            case QMessageBox::Retry: {
                tA->deleteBookings();
                //hier readTextfileMethode mit zeilenangabe von fehler der letzren Datei mitgeben input.seekg(zeile-1)
                //zeile 66 (delete methode) weg machen
                fileRead = false;
                break;
            }
            case QMessageBox::Discard: {
                tA->deleteBookings();
                std::cout << "Alle Buchungen geloescht" << std::endl;
                return;
            }
            case QMessageBox::No: {
                std::cout << "Details ausblenden" << std::endl;
                break;
            }
            case QMessageBox::Cancel: {
                std::cout << "Vorhandene Buchungen stehengelassen" << std::endl;
                return;
            }
            default:
                return;
            }

            fileRead = false;
        }

    }while(fileRead != true);
}

void MainWindow::pushButton_Auswaehlen()
{
    int id;

    if(tA->getBookings().size() != 0) {
        QString text = QInputDialog::getText(this, "Buchung suchen", "Buchungs-ID:");
        id = text.toInt();

        for(auto &k : tA->getBookings()) {
            if(k->getId() == id) {
                ui->listWidget->clear();
                ui->listWidget->addItem(k->showDetails());
                listDetails(id);
                return;
            } else {
                ui->listWidget->clear();
                ui->listWidget->addItem("Diese ID wurde aus unerklärlichen Gründen nicht gefunden");
            }
        }
    } else {
        ui->listWidget->clear();
        ui->listWidget->addItem("Die Buchungsliste enthält keine Einträge");
        //QMessageBox::information(this, "Buchungs-ID Suche", "Es kann keine Buchgung gesucht werden, da die Liste leer ist.");
    }
}

void MainWindow::pushBotton_Exportieren()
{
    if(tA->getBookings().size() != 0) {
        QString filename = QFileDialog::getSaveFileName(
                    this,
                    tr("Save File"),
                    "C://",
                    "Json File (*.json)"
                    );

        tA->exportJsonFile(filename);
    } else {
        ui->listWidget->addItem("Die Buchungsliste enthaelt keine Eintraege");
    }
}

void MainWindow::pushButton_Alle_anzeigen()
{
    ui->listWidget->clear();

    if(tA->getBookings().size() != 0) {
        for(size_t i = 0; i < tA->getBookings().size(); i++) {
            ui->listWidget->addItem(tA->getBookings().at(i)->showDetails());
        }
    } else {
        ui->listWidget->addItem("Die Buchungsliste enthaelt keine Eintraege");
    }
}

void MainWindow::doubleClickedListWidget() const
{
    std::string str;
    int id;

    QString qstr = ui->listWidget->currentItem()->text();
    QString subString = qstr.mid(4, 2);

    id = std::stoi(subString.toStdString());

    listDetails(id);
}

void MainWindow::listDetails(const int &id) const
{
    QString qstr;
    QDate qdate;

    for(auto &k : tA->getBookings()) {
        if(k->getId() == id) {
            //ui->listWidget->clear();
            //ui->listWidget->addItem(k->showDetails());

            switch (k->getBookingType()) {
            case Flight: {
                FlightBooking* fb = dynamic_cast<FlightBooking*>(k);
                ui->lineEdit->setText(QString::number(id));
                ui->lineEdit_2->setText(QString::fromStdString(fb->getFromDestination()));
                ui->lineEdit_3->setText(QString::fromStdString(fb->getToDestination()));
                qstr = QString::fromStdString(k->getFromDate());
                qdate = QDate::fromString(qstr, "yyyyMMdd");
                ui->dateEdit->setDate(qdate);
                ui->lineEdit_4->setText(QString::fromStdString(fb->getAirline()));
                ui->doubleSpinBox->setValue(fb->getPrice());
                break;
            }
            case Rent: {
                RentalCarReservation* rcr = dynamic_cast<RentalCarReservation*>(k);
                ui->lineEdit_5->setText(QString::number(id));
                ui->lineEdit_6->setText(QString::fromStdString(rcr->getCompany()));
                qstr = QString::fromStdString(k->getFromDate());
                qdate = QDate::fromString(qstr, "yyyyMMdd");
                ui->dateEdit_2->setDate(qdate);
                ui->lineEdit_7->setText(QString::fromStdString(rcr->getPickupLocation()));
                qstr = QString::fromStdString(k->getToDate());
                qdate = QDate::fromString(qstr, "yyyyMMdd");
                ui->dateEdit_3->setDate(qdate);
                ui->lineEdit_8->setText(QString::fromStdString(rcr->getReturnLocation()));
                ui->doubleSpinBox_2->setValue(rcr->getPrice());
                break;
            }
            case Hotel: {
                std::cout << "test" << std::endl;
                HotelBooking* hb = dynamic_cast<HotelBooking*>(k);
                ui->lineEdit_9->setText(QString::number(id));
                ui->lineEdit_10->setText(QString::fromStdString(hb->getHotel()));
                ui->lineEdit_11->setText(QString::fromStdString(hb->getTown()));
                qstr = QString::fromStdString(k->getFromDate());
                qdate = QDate::fromString(qstr, "yyyyMMdd");
                ui->dateEdit_4->setDate(qdate);
                qstr = QString::fromStdString(k->getToDate());
                qdate = QDate::fromString(qstr, "yyyyMMdd");
                ui->dateEdit_5->setDate(qdate);
                ui->doubleSpinBox_3->setValue(hb->getPrice());
                break;
            }
            default:
                break;
            }
            return;
        }
    }
}
