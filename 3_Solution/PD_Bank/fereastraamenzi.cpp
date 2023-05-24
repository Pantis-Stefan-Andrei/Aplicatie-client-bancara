#include "fereastraamenzi.h"
#include "ui_fereastraamenzi.h"

fereastraAmenzi::fereastraAmenzi(fereastraLogin* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastraAmenzi)
{
    ui->setupUi(this);
    this->parent=p;
}

fereastraAmenzi::~fereastraAmenzi()
{
    delete ui;
}

void fereastraAmenzi::on_pushButton_2_clicked()
{
    close();
    this->parent->show();
}


void fereastraAmenzi::on_pushButton_clicked()
{
    QString trimite="2_6_"+this->parent->client->getID()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="0")
        ui->textEdit->setText("Nu exista amenzi pentru tine!");
    else ui->textEdit->setText(verificare);
}


void fereastraAmenzi::on_pushButton_3_clicked()
{
    QString trimite="6_~_"+ui->lineEdit->text()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="1")
        ui->labelInformatie->setText("<font color='green'>Ai platit cu succes amenda!</font>");
    else ui->labelInformatie->setText("<font color='green'>Nu exista amenda cu ID-ul respectiv!</font>");
}

