#ifndef FEREASTRESTERGEREIBAN_H
#define FEREASTRESTERGEREIBAN_H

#include <QDialog>

#include "fereastraadmin.h"
#include "conectare.h"


namespace Ui {
class fereastreStergereIBAN;
}

class fereastreStergereIBAN : public QDialog
{
    Q_OBJECT

public:
    explicit fereastreStergereIBAN(fereastraAdmin* p,QWidget *parent = nullptr);
    ~fereastreStergereIBAN();

private slots:
    void on_fereastreStergereIBAN_accepted();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_textEdit_copyAvailable(bool b);

    void on_pushButton_3_clicked();

private:
    Ui::fereastreStergereIBAN *ui;
    conectare conexiune;
    fereastraAdmin* parent;
};

#endif // FEREASTRESTERGEREIBAN_H
