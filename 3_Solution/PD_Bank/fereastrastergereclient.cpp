#include "fereastrastergereclient.h"
#include "ui_fereastrastergereclient.h"

fereastraStergereClient::fereastraStergereClient(fereastraAdmin* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastraStergereClient)
{
    ui->setupUi(this);
    this->parent=p;
}

fereastraStergereClient::~fereastraStergereClient()
{
    delete ui;
}

void fereastraStergereClient::on_pushButton_clicked()
{
    QString trimite="4_1_"+ui->lineEdit->text()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="1")
            ui->labelInformatie->setText("<font color='green'>Stergere reusita!</font>");
    else ui->labelInformatie->setText("<font color='green'>Nu exista clientul cu ID-ul respectiv!</font>");
}


void fereastraStergereClient::on_pushButton_2_clicked()
{
    close();
    this->parent->show();
}


void fereastraStergereClient::on_pushButton_3_clicked()
{
    QString trimite="2_1_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);
    if(verificare=="0")
            ui->textEdit->setText("Nu exista inregistrari!");
    else ui->textEdit->setText(verificare);
}

