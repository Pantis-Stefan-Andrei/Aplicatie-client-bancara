#ifndef FEREASTRASTERGEAMENZI_H
#define FEREASTRASTERGEAMENZI_H

#include <QDialog>
#include "fereastraadmin.h"
#include "conectare.h"
namespace Ui {
class fereastrastergeAmenzi;
}

class fereastrastergeAmenzi : public QDialog
{
    Q_OBJECT

public:
    explicit fereastrastergeAmenzi(fereastraAdmin* p,QWidget *parent = nullptr);
    ~fereastrastergeAmenzi();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::fereastrastergeAmenzi *ui;
    conectare conexiune;
    fereastraAdmin* parent;
};

#endif // FEREASTRASTERGEAMENZI_H
