#include "fereastraadmin.h"
#include "ui_fereastraadmin.h"

#include "fereastrastergereclient.h"
#include "fereastrastergetranzactie.h"
#include "fereastrastergeamenzi.h"
#include "fereastrestergereiban.h"
#include "fereastrastergedepozit.h"
#include "fereastrastergecarduri.h"


fereastraAdmin::fereastraAdmin(MainWindow* m,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastraAdmin)
{
    ui->setupUi(this);
    this->parent=m;
}

fereastraAdmin::~fereastraAdmin()
{
    delete ui;
}

void fereastraAdmin::on_pushButton_clicked()
{
    close();
    fereastraStergereClient* fereastrastergere1=new fereastraStergereClient(this);
    fereastrastergere1->resize(800,500);
    fereastrastergere1->setWindowTitle("PD Bank");
    fereastrastergere1->show();
}


void fereastraAdmin::on_pushButtonStergeTranzactie_clicked()
{
    close();
    fereastrastergeTranzactie* fereastrastergere1=new fereastrastergeTranzactie(this);
    fereastrastergere1->resize(800,500);
    fereastrastergere1->setWindowTitle("PD Bank");
    fereastrastergere1->show();
}


void fereastraAdmin::on_pushButtonStergeAmenda_clicked()
{
    close();
    fereastrastergeAmenzi* fereastrastergere1=new fereastrastergeAmenzi(this);
    fereastrastergere1->resize(800,500);
    fereastrastergere1->setWindowTitle("PD Bank");
    fereastrastergere1->show();
}


void fereastraAdmin::on_pushButtonStergeIBAN_clicked()
{
    close();
    fereastreStergereIBAN* fereastrastergere1=new fereastreStergereIBAN(this);
    fereastrastergere1->resize(800,500);
    fereastrastergere1->setWindowTitle("PD Bank");
    fereastrastergere1->show();
}


void fereastraAdmin::on_pushButtonStergeIBAN_2_clicked()
{
    close();
    fereastrastergeDepozit* fereastrastergere1=new fereastrastergeDepozit(this);
    fereastrastergere1->resize(800,500);
    fereastrastergere1->setWindowTitle("PD Bank");
    fereastrastergere1->show();
}


void fereastraAdmin::on_pushButton_2_clicked()
{
    close();
    fereastrastergeCarduri* fereastrastergere1=new fereastrastergeCarduri(this);
    fereastrastergere1->resize(800,500);
    fereastrastergere1->setWindowTitle("PD Bank");
    fereastrastergere1->show();
}


void fereastraAdmin::on_pushButton_3_clicked()
{
    close();
    this->parent->show();
}

