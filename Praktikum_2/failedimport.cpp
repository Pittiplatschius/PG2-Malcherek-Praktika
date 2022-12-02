#include "failedimport.h"
#include "ui_failedimport.h"

FailedImport::FailedImport(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FailedImport)
{
    ui->setupUi(this);
}

FailedImport::~FailedImport()
{
    delete ui;
}
