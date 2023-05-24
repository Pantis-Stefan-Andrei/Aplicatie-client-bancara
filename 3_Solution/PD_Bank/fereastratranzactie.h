#ifndef FEREASTRATRANZACTIE_H
#define FEREASTRATRANZACTIE_H

#include <QDialog>
#include "conectare.h"
#include "fereastralogin.h"



namespace Ui {
class fereastraTranzactie;
}

class fereastraTranzactie : public QDialog
{
    Q_OBJECT

public:
    explicit fereastraTranzactie(fereastraLogin* p,QWidget *parent = nullptr);
    ~fereastraTranzactie();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::fereastraTranzactie *ui;
    fereastraLogin* parent;
    conectare conexiune;
};

#endif // FEREASTRATRANZACTIE_H
