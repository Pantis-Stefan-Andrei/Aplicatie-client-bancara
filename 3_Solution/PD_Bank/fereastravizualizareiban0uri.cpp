#include "fereastravizualizareiban0uri.h"
#include "ui_fereastravizualizareiban0uri.h"

fereastraVizualizareIBAN0uri::fereastraVizualizareIBAN0uri(fereastraLogin* p,QString v,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastraVizualizareIBAN0uri)
{
    ui->setupUi(this);
    this->parent=p;
    this->ui->textEdit->setText(v);
}

fereastraVizualizareIBAN0uri::~fereastraVizualizareIBAN0uri()
{
    delete ui;
}

void fereastraVizualizareIBAN0uri::on_pushButton_clicked()
{
    close();
    this->parent->show();
}

