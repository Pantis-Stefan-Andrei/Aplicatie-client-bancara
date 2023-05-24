#include "fereastraadaugabani.h"
#include "ui_fereastraadaugabani.h"



fereastraAdaugaBani::fereastraAdaugaBani(fereastraLogin* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastraAdaugaBani)
{

    ui->setupUi(this);
    this->parent=p;
}

fereastraAdaugaBani::~fereastraAdaugaBani()
{
    delete ui;
}

void fereastraAdaugaBani::on_pushButton_clicked()
{
    close();
    this->parent->show();
}


void fereastraAdaugaBani::on_pushButton_2_clicked()
{

}

