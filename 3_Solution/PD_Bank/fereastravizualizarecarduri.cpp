#include "fereastravizualizarecarduri.h"
#include "ui_fereastravizualizarecarduri.h"

fereastravizualizareCarduri::fereastravizualizareCarduri(fereastraLogin* p,QString verificare,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastravizualizareCarduri)
{
    ui->setupUi(this);
    this->parent=p;
    this->ui->textEdit->setText(verificare);
}

fereastravizualizareCarduri::~fereastravizualizareCarduri()
{
    delete ui;
}

void fereastravizualizareCarduri::on_pushButton_clicked()
{
    close();
    this->parent->show();
}

