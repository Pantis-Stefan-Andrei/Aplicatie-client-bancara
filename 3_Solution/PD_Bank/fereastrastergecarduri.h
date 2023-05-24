#ifndef FEREASTRASTERGECARDURI_H
#define FEREASTRASTERGECARDURI_H

#include <QDialog>
#include "fereastraadmin.h"
#include "conectare.h"


namespace Ui {
class fereastrastergeCarduri;
}

class fereastrastergeCarduri : public QDialog
{
    Q_OBJECT

public:
    explicit fereastrastergeCarduri(fereastraAdmin* p,QWidget *parent = nullptr);
    ~fereastrastergeCarduri();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::fereastrastergeCarduri *ui;
    conectare conexiune;
    fereastraAdmin* parent;
};

#endif // FEREASTRASTERGECARDURI_H
