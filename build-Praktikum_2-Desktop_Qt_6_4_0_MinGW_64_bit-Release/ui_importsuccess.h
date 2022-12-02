/********************************************************************************
** Form generated from reading UI file 'importsuccess.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTSUCCESS_H
#define UI_IMPORTSUCCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ImportSuccess
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *ImportSuccess)
    {
        if (ImportSuccess->objectName().isEmpty())
            ImportSuccess->setObjectName("ImportSuccess");
        ImportSuccess->resize(685, 191);
        pushButton = new QPushButton(ImportSuccess);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(580, 140, 80, 24));

        retranslateUi(ImportSuccess);
        QObject::connect(pushButton, &QPushButton::clicked, ImportSuccess, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(ImportSuccess);
    } // setupUi

    void retranslateUi(QDialog *ImportSuccess)
    {
        ImportSuccess->setWindowTitle(QCoreApplication::translate("ImportSuccess", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("ImportSuccess", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImportSuccess: public Ui_ImportSuccess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTSUCCESS_H
