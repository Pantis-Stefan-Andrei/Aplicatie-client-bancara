#ifndef FEREASTRAINREGISTRARE_H
#define FEREASTRAINREGISTRARE_H

#include <QDialog>
#include "conectare.h"
#include "mainwindow.h"
namespace Ui {
class fereastraInregistrare;
}

class fereastraInregistrare : public QDialog
{
    Q_OBJECT

public:
    explicit fereastraInregistrare(MainWindow* p,QWidget *parent = nullptr);
    ~fereastraInregistrare();
    conectare conexiune;

private slots:
    void on_pushButtonInregistrare_clicked();

    void on_pushButtonInapoi_clicked();

private:
    MainWindow* parent;
    Ui::fereastraInregistrare *ui;
};

#endif // FEREASTRAINREGISTRARE_H
