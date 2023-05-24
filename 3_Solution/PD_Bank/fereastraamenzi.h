#ifndef FEREASTRAAMENZI_H
#define FEREASTRAAMENZI_H

#include <QDialog>
#include "conectare.h"
#include "fereastralogin.h"

namespace Ui {
class fereastraAmenzi;
}

class fereastraAmenzi : public QDialog
{
    Q_OBJECT

public:
    explicit fereastraAmenzi(fereastraLogin* p,QWidget *parent = nullptr);
    ~fereastraAmenzi();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::fereastraAmenzi *ui;
    conectare conexiune;
    fereastraLogin* parent;
};

#endif // FEREASTRAAMENZI_H
