#include "fereastrastergeamenzi.h"
#include "ui_fereastrastergeamenzi.h"

fereastrastergeAmenzi::fereastrastergeAmenzi(fereastraAdmin* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastrastergeAmenzi)
{
    ui->setupUi(this);
    this->parent=p;
}

fereastrastergeAmenzi::~fereastrastergeAmenzi()
{
    delete ui;
}

void fereastrastergeAmenzi::on_pushButton_clicked()
{
    close();
    this->parent->show();
}


void fereastrastergeAmenzi::on_pushButton_2_clicked()
{
    QString trimite="4_5_"+ui->lineEdit->text()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="1")
        ui->labelInformatie->setText("<font color='green'>Stergere reusita!</font>");
    else ui->labelInformatie->setText("<font color='green'>Nu exista amenda cu ID-ul respectiv!</font>");
}


void fereastrastergeAmenzi::on_pushButton_3_clicked()
{
    QString trimite="2_6_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="0")
        ui->textEdit->setText("Nu exista inregistrari!");
    else ui->textEdit->setText(verificare);
}

