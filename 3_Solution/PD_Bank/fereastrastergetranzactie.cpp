#include "fereastrastergetranzactie.h"
#include "ui_fereastrastergetranzactie.h"

fereastrastergeTranzactie::fereastrastergeTranzactie(fereastraAdmin* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastrastergeTranzactie)
{
    ui->setupUi(this);
    this->parent=p;
}

fereastrastergeTranzactie::~fereastrastergeTranzactie()
{
    delete ui;
}

void fereastrastergeTranzactie::on_pushButton_clicked()
{
    close();
    this->parent->show();
}


void fereastrastergeTranzactie::on_pushButton_2_clicked()
{
    QString trimite="4_4_"+ui->lineEdit->text()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="1")
        ui->labelInformatie->setText("<font color='green'>Stergere reusita!</font>");
    else ui->labelInformatie->setText("<font color='green'>Nu exista tranzactia cu ID-ul respectiv!</font>");
}


void fereastrastergeTranzactie::on_pushButton_3_clicked()
{
    QString trimite="2_3_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="0")
        ui->textEdit->setText("Nu exista inregistrari!");
    else ui->textEdit->setText(verificare);
}

