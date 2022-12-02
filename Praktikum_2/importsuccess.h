#ifndef IMPORTSUCCESS_H
#define IMPORTSUCCESS_H

#include <QDialog>

namespace Ui {
class ImportSuccess;
}

class ImportSuccess : public QDialog
{
    Q_OBJECT

public:
    explicit ImportSuccess(QWidget *parent = nullptr);
    ~ImportSuccess();

private:
    Ui::ImportSuccess *ui;
};

#endif // IMPORTSUCCESS_H
