#ifndef FEREASTRAADAUGABANI_H
#define FEREASTRAADAUGABANI_H

#include <QDialog>

#include "conectare.h"
#include "fereastralogin.h"

namespace Ui {
class fereastraAdaugaBani;
}

class fereastraAdaugaBani : public QDialog
{
    Q_OBJECT

public:
    explicit fereastraAdaugaBani(fereastraLogin* p,QWidget *parent = nullptr);
    ~fereastraAdaugaBani();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::fereastraAdaugaBani *ui;
    fereastraLogin* parent;
    conectare conexiune;
};

#endif // FEREASTRAADAUGABANI_H
