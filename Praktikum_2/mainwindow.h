#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "travelagency.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    TravelAgency *tA;

private slots:
    void pushButton_Einlesen();
    void pushButton_Alle_anzeigen();
    void pushButton_Auswaehlen();
    void pushBotton_Exportieren();

    void doubleClickedListWidget() const;
    void listDetails(const int& id) const;
};
#endif // MAINWINDOW_H
