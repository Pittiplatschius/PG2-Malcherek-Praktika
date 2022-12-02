/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEinlesen;
    QAction *actionAuswaehlen;
    QAction *actionAlle_anzeigen;
    QAction *actionExportieren;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QDateEdit *dateEdit;
    QLineEdit *lineEdit_4;
    QDoubleSpinBox *doubleSpinBox;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QLabel *label_13;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_14;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QDateEdit *dateEdit_2;
    QLineEdit *lineEdit_7;
    QDateEdit *dateEdit_3;
    QLineEdit *lineEdit_8;
    QDoubleSpinBox *doubleSpinBox_2;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_15;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_21;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QDateEdit *dateEdit_4;
    QDateEdit *dateEdit_5;
    QDoubleSpinBox *doubleSpinBox_3;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QMenu *menuBuchung;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(750, 487);
        actionEinlesen = new QAction(MainWindow);
        actionEinlesen->setObjectName("actionEinlesen");
        actionEinlesen->setCheckable(false);
        actionEinlesen->setChecked(false);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionEinlesen->setIcon(icon);
        actionAuswaehlen = new QAction(MainWindow);
        actionAuswaehlen->setObjectName("actionAuswaehlen");
        QIcon icon1;
        iconThemeName = QString::fromUtf8("edit-find");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionAuswaehlen->setIcon(icon1);
        actionAlle_anzeigen = new QAction(MainWindow);
        actionAlle_anzeigen->setObjectName("actionAlle_anzeigen");
        QIcon icon2;
        iconThemeName = QString::fromUtf8("dialog-information");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionAlle_anzeigen->setIcon(icon2);
        actionExportieren = new QAction(MainWindow);
        actionExportieren->setObjectName("actionExportieren");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        horizontalLayout->addWidget(listWidget);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 141, 251));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");
        label_7->setFont(font);

        verticalLayout->addWidget(label_7);

        verticalLayoutWidget_2 = new QWidget(tab);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(160, 10, 160, 261));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(verticalLayoutWidget_2);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout_2->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_3->setObjectName("lineEdit_3");

        verticalLayout_2->addWidget(lineEdit_3);

        dateEdit = new QDateEdit(verticalLayoutWidget_2);
        dateEdit->setObjectName("dateEdit");

        verticalLayout_2->addWidget(dateEdit);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_4->setObjectName("lineEdit_4");

        verticalLayout_2->addWidget(lineEdit_4);

        doubleSpinBox = new QDoubleSpinBox(verticalLayoutWidget_2);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setMaximum(99999.990000000005239);

        verticalLayout_2->addWidget(doubleSpinBox);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayoutWidget_3 = new QWidget(tab_2);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 141, 291));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName("label_8");
        label_8->setFont(font);

        verticalLayout_4->addWidget(label_8);

        label_13 = new QLabel(verticalLayoutWidget_3);
        label_13->setObjectName("label_13");
        label_13->setFont(font);

        verticalLayout_4->addWidget(label_13);

        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName("label_9");
        label_9->setFont(font);

        verticalLayout_4->addWidget(label_9);

        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName("label_12");
        label_12->setFont(font);

        verticalLayout_4->addWidget(label_12);

        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName("label_10");
        label_10->setFont(font);

        verticalLayout_4->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName("label_11");
        label_11->setFont(font);

        verticalLayout_4->addWidget(label_11);

        label_14 = new QLabel(verticalLayoutWidget_3);
        label_14->setObjectName("label_14");
        label_14->setFont(font);

        verticalLayout_4->addWidget(label_14);

        verticalLayoutWidget_5 = new QWidget(tab_2);
        verticalLayoutWidget_5->setObjectName("verticalLayoutWidget_5");
        verticalLayoutWidget_5->setGeometry(QRect(160, 10, 160, 291));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        lineEdit_5 = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_5->setObjectName("lineEdit_5");

        verticalLayout_6->addWidget(lineEdit_5);

        lineEdit_6 = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_6->setObjectName("lineEdit_6");

        verticalLayout_6->addWidget(lineEdit_6);

        dateEdit_2 = new QDateEdit(verticalLayoutWidget_5);
        dateEdit_2->setObjectName("dateEdit_2");

        verticalLayout_6->addWidget(dateEdit_2);

        lineEdit_7 = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_7->setObjectName("lineEdit_7");

        verticalLayout_6->addWidget(lineEdit_7);

        dateEdit_3 = new QDateEdit(verticalLayoutWidget_5);
        dateEdit_3->setObjectName("dateEdit_3");

        verticalLayout_6->addWidget(dateEdit_3);

        lineEdit_8 = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_8->setObjectName("lineEdit_8");

        verticalLayout_6->addWidget(lineEdit_8);

        doubleSpinBox_2 = new QDoubleSpinBox(verticalLayoutWidget_5);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");
        doubleSpinBox_2->setMaximum(99999.990000000005239);

        verticalLayout_6->addWidget(doubleSpinBox_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        verticalLayoutWidget_4 = new QWidget(tab_3);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(10, 10, 141, 261));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(verticalLayoutWidget_4);
        label_15->setObjectName("label_15");
        label_15->setFont(font);

        verticalLayout_5->addWidget(label_15);

        label_18 = new QLabel(verticalLayoutWidget_4);
        label_18->setObjectName("label_18");
        label_18->setFont(font);

        verticalLayout_5->addWidget(label_18);

        label_19 = new QLabel(verticalLayoutWidget_4);
        label_19->setObjectName("label_19");
        label_19->setFont(font);

        verticalLayout_5->addWidget(label_19);

        label_16 = new QLabel(verticalLayoutWidget_4);
        label_16->setObjectName("label_16");
        label_16->setFont(font);

        verticalLayout_5->addWidget(label_16);

        label_17 = new QLabel(verticalLayoutWidget_4);
        label_17->setObjectName("label_17");
        label_17->setFont(font);

        verticalLayout_5->addWidget(label_17);

        label_21 = new QLabel(verticalLayoutWidget_4);
        label_21->setObjectName("label_21");
        label_21->setFont(font);

        verticalLayout_5->addWidget(label_21);

        verticalLayoutWidget_6 = new QWidget(tab_3);
        verticalLayoutWidget_6->setObjectName("verticalLayoutWidget_6");
        verticalLayoutWidget_6->setGeometry(QRect(160, 10, 160, 261));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        lineEdit_9 = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_9->setObjectName("lineEdit_9");

        verticalLayout_7->addWidget(lineEdit_9);

        lineEdit_10 = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_10->setObjectName("lineEdit_10");

        verticalLayout_7->addWidget(lineEdit_10);

        lineEdit_11 = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_11->setObjectName("lineEdit_11");

        verticalLayout_7->addWidget(lineEdit_11);

        dateEdit_4 = new QDateEdit(verticalLayoutWidget_6);
        dateEdit_4->setObjectName("dateEdit_4");

        verticalLayout_7->addWidget(dateEdit_4);

        dateEdit_5 = new QDateEdit(verticalLayoutWidget_6);
        dateEdit_5->setObjectName("dateEdit_5");

        verticalLayout_7->addWidget(dateEdit_5);

        doubleSpinBox_3 = new QDoubleSpinBox(verticalLayoutWidget_6);
        doubleSpinBox_3->setObjectName("doubleSpinBox_3");
        doubleSpinBox_3->setMaximum(99999.990000000005239);

        verticalLayout_7->addWidget(doubleSpinBox_3);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 750, 21));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName("menuDatei");
        menuBuchung = new QMenu(menubar);
        menuBuchung->setObjectName("menuBuchung");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuDatei->menuAction());
        menubar->addAction(menuBuchung->menuAction());
        menuDatei->addSeparator();
        menuDatei->addAction(actionEinlesen);
        menuDatei->addAction(actionExportieren);
        menuBuchung->addAction(actionAuswaehlen);
        menuBuchung->addAction(actionAlle_anzeigen);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionEinlesen->setText(QCoreApplication::translate("MainWindow", "Einlesen", nullptr));
#if QT_CONFIG(shortcut)
        actionEinlesen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAuswaehlen->setText(QCoreApplication::translate("MainWindow", "Ausw\303\244hlen", nullptr));
#if QT_CONFIG(shortcut)
        actionAuswaehlen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAlle_anzeigen->setText(QCoreApplication::translate("MainWindow", "Alle anzeigen", nullptr));
#if QT_CONFIG(shortcut)
        actionAlle_anzeigen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExportieren->setText(QCoreApplication::translate("MainWindow", "Exportieren", nullptr));
#if QT_CONFIG(shortcut)
        actionExportieren->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(whatsthis)
        tabWidget->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>ass</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        tab->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Startflughafen", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Zielflughafen", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Startdatum", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Fluggesellschaft", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Preis", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Flugbuchung", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Unternehmen", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Abholdatum", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Abholort", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Abgabedatum", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Abgabeort", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Preis", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Mietwagenreservierung", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Hotel", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Stadt", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Ankunftsdatum", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Abreisedatum", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Preis", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Hotelreservierung", nullptr));
        menuDatei->setTitle(QCoreApplication::translate("MainWindow", "Datei", nullptr));
        menuBuchung->setTitle(QCoreApplication::translate("MainWindow", "Buchung", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
