#ifndef FEREASTRASTERGERECLIENT_H
#define FEREASTRASTERGERECLIENT_H

#include <QDialog>

#include "fereastraadmin.h"
#include "conectare.h"

namespace Ui {
class fereastraStergereClient;
}

class fereastraStergereClient : public QDialog
{
    Q_OBJECT

public:
    explicit fereastraStergereClient(fereastraAdmin* a,QWidget *parent = nullptr);
    ~fereastraStergereClient();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::fereastraStergereClient *ui;
    fereastraAdmin* parent;
    conectare conexiune;
};

#endif // FEREASTRASTERGERECLIENT_H
