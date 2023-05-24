#include "fereastravizualizaretranzactii.h"
#include "ui_fereastravizualizaretranzactii.h"

fereastraVizualizareTranzactii::fereastraVizualizareTranzactii(fereastraLogin* p, QString verificare,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastraVizualizareTranzactii)
{
    ui->setupUi(this);
    this->parent=p;
    this->ui->textEdit->setText(verificare);
}

fereastraVizualizareTranzactii::~fereastraVizualizareTranzactii()
{
    delete ui;
}

void fereastraVizualizareTranzactii::on_pushButton_clicked()
{
    close();
    this->parent->show();
}

