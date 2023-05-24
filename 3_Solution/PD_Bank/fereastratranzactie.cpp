#include "fereastratranzactie.h"
#include "ui_fereastratranzactie.h"

fereastraTranzactie::fereastraTranzactie(fereastraLogin* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastraTranzactie)
{
    ui->setupUi(this);
    this->parent=p;
}

fereastraTranzactie::~fereastraTranzactie()
{
    delete ui;
}

void fereastraTranzactie::on_pushButton_2_clicked()
{
    close();
    this->parent->show();
}


void fereastraTranzactie::on_pushButton_clicked()
{
    QString trimite="3_"+this->parent->client->getID()+"_"+ui->lineEditIBAN->text()+"_"+ui->lineEditSuma->text()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);
    if(verificare!="0")
        ui->labelInformatie->setText("<font color='green'>Trimitere reusita!</font>");
    else ui->labelInformatie->setText("<font color='green'>Nu exista acest IBAN/ai prea putin bani!</font>");
}

