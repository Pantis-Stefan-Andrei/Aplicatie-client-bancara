#include "fereastrabani.h"
#include "ui_fereastrabani.h"

fereastraBani::fereastraBani(fereastraLogin* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastraBani)
{
    ui->setupUi(this);
    this->parent=p;
}

fereastraBani::~fereastraBani()
{
    delete ui;
}

void fereastraBani::on_pushButton_2_clicked()
{
    close();
    this->parent->show();
}


void fereastraBani::on_pushButton_clicked()
{
    QString trimite="1_~_"+ui->lineEdit->text()+"_"+parent->client->getID()+"_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);
    if(verificare!="0")
        ui->label_2->setText("Banii au fost introdusi!");
}

