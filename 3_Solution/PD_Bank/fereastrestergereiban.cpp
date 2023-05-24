#include "fereastrestergereiban.h"
#include "ui_fereastrestergereiban.h"

fereastreStergereIBAN::fereastreStergereIBAN(fereastraAdmin* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastreStergereIBAN)
{
    ui->setupUi(this);
    this->parent=p;
}

fereastreStergereIBAN::~fereastreStergereIBAN()
{
    delete ui;
}




void fereastreStergereIBAN::on_pushButton_2_clicked()
{
    QString trimite="4_3_"+ui->lineEdit->text()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="1")
        ui->labelInformatie->setText("<font color='green'>Stergere reusita!</font>");
    else ui->labelInformatie->setText("<font color='green'>Nu exista IBAN-ul cu ID-ul respectiv!</font>");
}


void fereastreStergereIBAN::on_pushButton_clicked()
{
    close();
    this->parent->show();
}





void fereastreStergereIBAN::on_pushButton_3_clicked()
{
    QString trimite="2_2_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="0")
        ui->textEdit->setText("Nu exista inregistrari!");
    else ui->textEdit->setText(verificare);
}

