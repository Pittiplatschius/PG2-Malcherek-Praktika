#ifndef FAILEDIMPORT_H
#define FAILEDIMPORT_H

#include <QGroupBox>

namespace Ui {
class FailedImport;
}

class FailedImport : public QGroupBox
{
    Q_OBJECT

public:
    explicit FailedImport(QWidget *parent = nullptr);
    ~FailedImport();

private:
    Ui::FailedImport *ui;
};

#endif // FAILEDIMPORT_H
