#ifndef FEREASTRASTERGETRANZACTIE_H
#define FEREASTRASTERGETRANZACTIE_H

#include <QDialog>
#include <fereastraadmin.h>
#include <conectare.h>

namespace Ui {
class fereastrastergeTranzactie;
}

class fereastrastergeTranzactie : public QDialog
{
    Q_OBJECT

public:
    explicit fereastrastergeTranzactie(fereastraAdmin* p,QWidget *parent = nullptr);
    ~fereastrastergeTranzactie();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::fereastrastergeTranzactie *ui;
    fereastraAdmin* parent;
    conectare conexiune;
};

#endif // FEREASTRASTERGETRANZACTIE_H
