#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "travelagency.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class TravelAgencyUI : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    TravelAgency *tA;

public:
    TravelAgencyUI(QWidget *parent = nullptr);
    ~TravelAgencyUI();

private slots:
    void pushButton_Einlesen();
    void pushButton_Alle_anzeigen();
    void pushButton_BuchungSuchen();
    void pushBotton_Exportieren();
    void pushButton_Liste_sortieren();
    void pushButton_KundeSuchen();

    void doubleClickedListWidget() const;
    void listDetails(const int& id) const;
};
#endif // MAINWINDOW_H
