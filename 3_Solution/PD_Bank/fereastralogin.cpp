#include "fereastralogin.h"
#include "ui_fereastralogin.h"
#include "fereastravizualizarecarduri.h"
#include "fereastravizualizaretranzactii.h"
#include "fereastravizualizareiban0uri.h"
#include "fereastratranzactie.h"
#include "fereastraamenzi.h"
#include "fereastrabani.h"

fereastraLogin::fereastraLogin(MainWindow* p,QString array,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastraLogin)
{
    ui->setupUi(this);
    this->parent=p;
    QStringList list=array.split("_");

    QString ID=list[0];
    QString nume=list[1];
    QString prenume=list[2];
    QString CNP=list[3];
    QString utilizator=list[4];
    QString parola=list[5];
    QString telefon=list[6];
    QString email=list[7];
    this->client=new Utilizator(nume,prenume,CNP,telefon,email,utilizator,parola,ID);
    this->ui->labelNume->setText(nume);
}

fereastraLogin::~fereastraLogin()
{
    delete ui;
}

void fereastraLogin::on_pushButtonInapoi_clicked()
{

    close();
    this->parent->show();
    this->client->printeaza();
}


void fereastraLogin::on_pushButton_clicked()
{
    QString trimite="2_1_"+client->getID()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    QStringList list=verificare.split(" ");

    QString nume=list[1];
    QString prenume=list[2];
    QString CNP=list[3];
    QString telefon=list[6];
    QString email=list[7];

    client->setSold(list[8]);

    QString Date=nume+" "+prenume+" "+CNP+" "+email+" "+telefon;

    ui->labelDate->setText(Date);

}


void fereastraLogin::on_pushButton_2_clicked()
{
    QString trimite="2_1_"+client->getID()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    QStringList list=verificare.split(" ");

    QString sold=list[8];
    QStringList list2=sold.split("\n");
    QString soldnou=list2[0];
    ui->labelDateSold->setText(soldnou+" lei");

}


void fereastraLogin::on_pushButton_3_clicked()
{
    QString trimite="2_5_"+client->getID()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="0")
        verificare="Nu exista carduri!";
    close();
    fereastravizualizareCarduri* fereastra=new fereastravizualizareCarduri(this,verificare);
    fereastra->resize(800,500);
    fereastra->setWindowTitle("PD Bank");
    fereastra->show();

}


void fereastraLogin::on_pushButton_4_clicked()
{
    QString trimite="2_3_"+client->getID()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="0")
        verificare="Nu exista tranzactii!";
    close();
    fereastraVizualizareTranzactii* fereastra=new fereastraVizualizareTranzactii(this,verificare);
    fereastra->resize(800,500);
    fereastra->setWindowTitle("PD Bank");
    fereastra->show();
}


void fereastraLogin::on_pushButton_5_clicked()
{
    QString trimite="2_2_"+client->getID()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);

    if(verificare=="0")
        verificare="Nu exista carduri!";
    close();

    fereastraVizualizareIBAN0uri* fereastra=new fereastraVizualizareIBAN0uri(this,verificare);
    fereastra->resize(800,500);
    fereastra->setWindowTitle("PD Bank");
    fereastra->show();
}


void fereastraLogin::on_pushButton_6_clicked()
{
    QString trimite="7_"+client->getID()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);
    if(verificare!="0")
        ui->label_2->setText("S-a generat un IBAN nou!");
}


void fereastraLogin::on_pushButton_7_clicked()
{
    close();
    fereastraTranzactie* fereastra=new fereastraTranzactie(this);
    fereastra->resize(800,500);
    fereastra->setWindowTitle("PD Bank");
    fereastra->show();
}


void fereastraLogin::on_pushButton_8_clicked()
{
    close();
    fereastraAmenzi* fereastra=new fereastraAmenzi(this);
    fereastra->resize(800,500);
    fereastra->setWindowTitle("PD Bank");
    fereastra->show();
}


void fereastraLogin::on_pushButton_9_clicked()
{
    QString trimite="8_"+client->getID()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);
    if(verificare!="0")
        ui->label_3->setText("S-a generat un card nou!");
}


void fereastraLogin::on_pushButton_10_clicked()
{
    close();
    fereastraBani* fereastra=new fereastraBani(this);
    fereastra->resize(800,500);
    fereastra->setWindowTitle("PD Bank");
    fereastra->show();
}

