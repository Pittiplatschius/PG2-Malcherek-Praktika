#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionEinlesen, SIGNAL(triggered(bool)),this, SLOT(pushButton_Einlesen()));
    connect(ui->actionAuswaehlen, SIGNAL(triggered(bool)), this, SLOT(pushButton_Auswaehlen()));
    connect(ui->actionAlle_anzeigen, SIGNAL(triggered(bool)), this, SLOT(pushButton_Alle_anzeigen()));
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
            tA.readFile(filename);
            fileRead = true;
            QMessageBox::information(this, tr("Datei erfolgreich eingelesen"), tA.bookedMessage());
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            qstr = QString::fromStdString(e.what());

            QMessageBox::StandardButton reply;
            reply = QMessageBox::warning(this, "Fehler beim Einlesen der Buchung", qstr,
                                          QMessageBox::Retry | QMessageBox::Discard |
                                          QMessageBox::No | QMessageBox::Cancel);

            switch (reply) {
            case QMessageBox::Retry: {
                tA.deleteBookings();
                fileRead = false;
                break;
            }
            case QMessageBox::Discard: {
                tA.deleteBookings();
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
    int iD;

    if(tA.getBookings().size() != 0) {
        QString text = QInputDialog::getText(this, "Buchung suchen", "Buchungs-ID:");
        iD = text.toInt();



        if(iD == 0) {
            ui->listWidget->clear();
            ui->listWidget->addItem("Diese ID existiert nicht in der Buchungsliste.");
            //QMessageBox::information(this, "Buchungs-ID Suche", "Diese ID existiert nicht in der Buchungsliste.");
        }

    } else {
        ui->listWidget->clear();
        ui->listWidget->addItem("Die Buchungsliste enthält keine Einträge");
        //QMessageBox::information(this, "Buchungs-ID Suche", "Es kann keine Buchgung gesucht werden, da die Liste leer ist.");
    }
}

void MainWindow::pushButton_Alle_anzeigen()
{
    ui->listWidget->clear();

    if(tA.getBookings().size() != 0) {
        for(size_t i = 0; i < tA.getBookings().size(); i++) {
            ui->listWidget->addItem(tA.getBookings().at(i)->showDetails());
        }
    } else {
        ui->listWidget->addItem("Es wurden keine Einträge in der Buchungsliste gefunden");
    }
}


