#ifndef FEREASTRALOGIN_H
#define FEREASTRALOGIN_H

#include <QDialog>

#include "mainwindow.h"
#include "utilizator.h"
#include "conectare.h"

namespace Ui {
class fereastraLogin;
}

class fereastraLogin : public QDialog
{
    Q_OBJECT

public:
    explicit fereastraLogin(MainWindow* p,QString array,QWidget *parent = nullptr);
    ~fereastraLogin();
    int ID_Client;
    Utilizator* client;
private slots:
    void on_pushButtonInapoi_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::fereastraLogin *ui;
    MainWindow* parent;
    conectare conexiune;
};

#endif // FEREASTRALOGIN_H
