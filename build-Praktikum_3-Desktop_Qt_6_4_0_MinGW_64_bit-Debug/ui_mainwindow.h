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
#include <QtWidgets/QSpacerItem>
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
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QDateEdit *dateEdit;
    QLineEdit *lineEdit_4;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QDateEdit *dateEdit_2;
    QLineEdit *lineEdit_7;
    QDateEdit *dateEdit_3;
    QLineEdit *lineEdit_8;
    QDoubleSpinBox *doubleSpinBox_2;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QDateEdit *dateEdit_4;
    QDateEdit *dateEdit_5;
    QDoubleSpinBox *doubleSpinBox_3;
    QMenuBar *menubar;
    QMenu *menuEinlesen;
    QMenu *menuBuchungen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionEinlesen = new QAction(MainWindow);
        actionEinlesen->setObjectName("actionEinlesen");
        actionAuswaehlen = new QAction(MainWindow);
        actionAuswaehlen->setObjectName("actionAuswaehlen");
        actionAlle_anzeigen = new QAction(MainWindow);
        actionAlle_anzeigen->setObjectName("actionAlle_anzeigen");
        actionExportieren = new QAction(MainWindow);
        actionExportieren->setObjectName("actionExportieren");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setMinimumSize(QSize(388, 0));
        listWidget->setMaximumSize(QSize(388, 16777215));

        horizontalLayout_2->addWidget(listWidget);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayout_4 = new QHBoxLayout(tab);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(tab);
        label->setObjectName("label");

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");

        verticalLayout_3->addWidget(label_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_4->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout_4->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName("lineEdit_3");

        verticalLayout_4->addWidget(lineEdit_3);

        dateEdit = new QDateEdit(tab);
        dateEdit->setObjectName("dateEdit");

        verticalLayout_4->addWidget(dateEdit);

        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName("lineEdit_4");

        verticalLayout_4->addWidget(lineEdit_4);

        doubleSpinBox = new QDoubleSpinBox(tab);
        doubleSpinBox->setObjectName("doubleSpinBox");

        verticalLayout_4->addWidget(doubleSpinBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_4->addLayout(verticalLayout_4);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_5 = new QHBoxLayout(tab_2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_7 = new QLabel(tab_2);
        label_7->setObjectName("label_7");

        verticalLayout_5->addWidget(label_7);

        label_8 = new QLabel(tab_2);
        label_8->setObjectName("label_8");

        verticalLayout_5->addWidget(label_8);

        label_9 = new QLabel(tab_2);
        label_9->setObjectName("label_9");

        verticalLayout_5->addWidget(label_9);

        label_10 = new QLabel(tab_2);
        label_10->setObjectName("label_10");

        verticalLayout_5->addWidget(label_10);

        label_11 = new QLabel(tab_2);
        label_11->setObjectName("label_11");

        verticalLayout_5->addWidget(label_11);

        label_12 = new QLabel(tab_2);
        label_12->setObjectName("label_12");

        verticalLayout_5->addWidget(label_12);

        label_13 = new QLabel(tab_2);
        label_13->setObjectName("label_13");

        verticalLayout_5->addWidget(label_13);


        horizontalLayout_5->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        lineEdit_5 = new QLineEdit(tab_2);
        lineEdit_5->setObjectName("lineEdit_5");

        verticalLayout_6->addWidget(lineEdit_5);

        lineEdit_6 = new QLineEdit(tab_2);
        lineEdit_6->setObjectName("lineEdit_6");

        verticalLayout_6->addWidget(lineEdit_6);

        dateEdit_2 = new QDateEdit(tab_2);
        dateEdit_2->setObjectName("dateEdit_2");

        verticalLayout_6->addWidget(dateEdit_2);

        lineEdit_7 = new QLineEdit(tab_2);
        lineEdit_7->setObjectName("lineEdit_7");

        verticalLayout_6->addWidget(lineEdit_7);

        dateEdit_3 = new QDateEdit(tab_2);
        dateEdit_3->setObjectName("dateEdit_3");

        verticalLayout_6->addWidget(dateEdit_3);

        lineEdit_8 = new QLineEdit(tab_2);
        lineEdit_8->setObjectName("lineEdit_8");

        verticalLayout_6->addWidget(lineEdit_8);

        doubleSpinBox_2 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");

        verticalLayout_6->addWidget(doubleSpinBox_2);


        horizontalLayout_5->addLayout(verticalLayout_6);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        horizontalLayout_6 = new QHBoxLayout(tab_3);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_14 = new QLabel(tab_3);
        label_14->setObjectName("label_14");

        verticalLayout_7->addWidget(label_14);

        label_15 = new QLabel(tab_3);
        label_15->setObjectName("label_15");

        verticalLayout_7->addWidget(label_15);

        label_16 = new QLabel(tab_3);
        label_16->setObjectName("label_16");

        verticalLayout_7->addWidget(label_16);

        label_17 = new QLabel(tab_3);
        label_17->setObjectName("label_17");

        verticalLayout_7->addWidget(label_17);

        label_18 = new QLabel(tab_3);
        label_18->setObjectName("label_18");

        verticalLayout_7->addWidget(label_18);

        label_19 = new QLabel(tab_3);
        label_19->setObjectName("label_19");

        verticalLayout_7->addWidget(label_19);


        horizontalLayout_6->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        lineEdit_9 = new QLineEdit(tab_3);
        lineEdit_9->setObjectName("lineEdit_9");

        verticalLayout_8->addWidget(lineEdit_9);

        lineEdit_10 = new QLineEdit(tab_3);
        lineEdit_10->setObjectName("lineEdit_10");

        verticalLayout_8->addWidget(lineEdit_10);

        lineEdit_11 = new QLineEdit(tab_3);
        lineEdit_11->setObjectName("lineEdit_11");

        verticalLayout_8->addWidget(lineEdit_11);

        dateEdit_4 = new QDateEdit(tab_3);
        dateEdit_4->setObjectName("dateEdit_4");

        verticalLayout_8->addWidget(dateEdit_4);

        dateEdit_5 = new QDateEdit(tab_3);
        dateEdit_5->setObjectName("dateEdit_5");

        verticalLayout_8->addWidget(dateEdit_5);

        doubleSpinBox_3 = new QDoubleSpinBox(tab_3);
        doubleSpinBox_3->setObjectName("doubleSpinBox_3");

        verticalLayout_8->addWidget(doubleSpinBox_3);


        horizontalLayout_6->addLayout(verticalLayout_8);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout_2->addWidget(tabWidget);


        horizontalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuEinlesen = new QMenu(menubar);
        menuEinlesen->setObjectName("menuEinlesen");
        menuBuchungen = new QMenu(menubar);
        menuBuchungen->setObjectName("menuBuchungen");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuEinlesen->menuAction());
        menubar->addAction(menuBuchungen->menuAction());
        menuEinlesen->addAction(actionEinlesen);
        menuEinlesen->addAction(actionExportieren);
        menuBuchungen->addAction(actionAuswaehlen);
        menuBuchungen->addAction(actionAlle_anzeigen);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionEinlesen->setText(QCoreApplication::translate("MainWindow", "Einlesen", nullptr));
        actionAuswaehlen->setText(QCoreApplication::translate("MainWindow", "Ausw\303\244hlen", nullptr));
        actionAlle_anzeigen->setText(QCoreApplication::translate("MainWindow", "Alle anzeigen", nullptr));
        actionExportieren->setText(QCoreApplication::translate("MainWindow", "Exportieren", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Startflughafen", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Zielflughafen", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Startdatum", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Fluggesellschaft", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Preis", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Flugbuchung", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Unternehmen", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Abholdatum", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Abholort", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Abgabedatum", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Abgabeort", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Preis", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Mietwagenreservierung", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Hotel", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Stadt", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Ankunfsdatum", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Anreisedatum", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Preis", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Hotelbuchung", nullptr));
        menuEinlesen->setTitle(QCoreApplication::translate("MainWindow", "Datei", nullptr));
        menuBuchungen->setTitle(QCoreApplication::translate("MainWindow", "Buchungen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
