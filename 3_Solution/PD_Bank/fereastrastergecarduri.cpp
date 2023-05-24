#include "fereastrastergecarduri.h"
#include "ui_fereastrastergecarduri.h"

fereastrastergeCarduri::fereastrastergeCarduri(fereastraAdmin* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastrastergeCarduri)
{
    ui->setupUi(this);
    this->parent=p;
}

fereastrastergeCarduri::~fereastrastergeCarduri()
{
    delete ui;
}

void fereastrastergeCarduri::on_pushButton_clicked()
{
    close();
    this->parent->show();
}


void fereastrastergeCarduri::on_pushButton_2_clicked()
{
    QString trimite="4_6_"+ui->lineEdit->text()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="1")
        ui->label->setText("<font color='green'>Stergere reusita!</font>");
    else ui->label->setText("<font color='green'>Nu exista cardul cu ID-ul respectiv!</font>");
}


void fereastrastergeCarduri::on_pushButton_3_clicked()
{
    QString trimite="2_5_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="0")
        ui->textEdit->setText("Nu exista inregistrari!");
    else ui->textEdit->setText(verificare);
}

