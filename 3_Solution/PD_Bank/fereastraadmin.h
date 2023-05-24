#ifndef FEREASTRAADMIN_H
#define FEREASTRAADMIN_H

#include <QDialog>

#include "mainwindow.h"

namespace Ui {
class fereastraAdmin;
}

class fereastraAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit fereastraAdmin(MainWindow* m,QWidget *parent = nullptr);
    ~fereastraAdmin();

private slots:
    void on_pushButton_clicked();

    void on_pushButtonStergeTranzactie_clicked();

    void on_pushButtonStergeAmenda_clicked();

    void on_pushButtonStergeIBAN_clicked();

    void on_pushButtonStergeIBAN_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::fereastraAdmin *ui;
    MainWindow* parent;
};

#endif // FEREASTRAADMIN_H
