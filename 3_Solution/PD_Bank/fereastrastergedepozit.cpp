#include "fereastrastergedepozit.h"
#include "ui_fereastrastergedepozit.h"

fereastrastergeDepozit::fereastrastergeDepozit(fereastraAdmin* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastrastergeDepozit)
{
    this->parent=p;
    ui->setupUi(this);
}

fereastrastergeDepozit::~fereastrastergeDepozit()
{
    delete ui;
}

void fereastrastergeDepozit::on_pushButton_clicked()
{
    QString trimite="4_2_"+ui->lineEdit->text()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="1")
        ui->labelInformatie->setText("<font color='green'>Stergere reusita!</font>");
    else ui->labelInformatie->setText("<font color='green'>Nu exista depozitul cu ID-ul respectiv!</font>");
}


void fereastrastergeDepozit::on_pushButton_2_clicked()
{
    close();
    this->parent->show();
}


void fereastrastergeDepozit::on_pushButton_3_clicked()
{
    QString trimite="2_4_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="0")
        ui->textEdit->setText("Nu exista inregistrari!");
    else ui->textEdit->setText(verificare);

}

