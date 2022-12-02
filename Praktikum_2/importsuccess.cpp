#include "importsuccess.h"
#include "ui_importsuccess.h"

ImportSuccess::ImportSuccess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportSuccess)
{
    ui->setupUi(this);
}

ImportSuccess::~ImportSuccess()
{
    delete ui;
}
