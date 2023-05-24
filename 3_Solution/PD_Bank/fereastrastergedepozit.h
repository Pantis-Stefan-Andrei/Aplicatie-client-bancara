#ifndef FEREASTRASTERGEDEPOZIT_H
#define FEREASTRASTERGEDEPOZIT_H

#include <QDialog>
#include "fereastraadmin.h"
#include "conectare.h"


namespace Ui {
class fereastrastergeDepozit;
}

class fereastrastergeDepozit : public QDialog
{
    Q_OBJECT

public:
    explicit fereastrastergeDepozit(fereastraAdmin* p,QWidget *parent = nullptr);
    ~fereastrastergeDepozit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::fereastrastergeDepozit *ui;
    conectare conexiune;
    fereastraAdmin* parent;
};

#endif // FEREASTRASTERGEDEPOZIT_H
