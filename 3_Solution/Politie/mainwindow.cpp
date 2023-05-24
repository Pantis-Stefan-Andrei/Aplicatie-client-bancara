
#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    QString trimite="2_1_";
    QByteArray byteArray=trimite.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);
    QString text;
    if(verificare=="0")
        ui->textEdit->setText("Nu exista inregistrari!");
    else {
        ui->textEdit->setText(verificare);
    }
}


void MainWindow::on_pushButton_clicked()
{
    int error=0;
    if(ui->lineEditData->text().length()==0 || ui->lineEditDescriere->text().length()==0 || ui->lineEditID->text().length()==0 || ui->lineEditNume->text().length()==0 || ui->lineEditSuma->text().length()==0)
        error=1;
    if(error==1)
    {
         ui->labelInformatie->setText("<font color='red'>Toate campurile sunt obligatorii!</font>");
    }
    if(error==0)
    {
         QString trimite="6_"+ui->lineEditNume->text()+"_"+ui->lineEditDescriere->text()+"_"+ui->lineEditData->text()+"_"+ui->lineEditID->text()+"_"+ui->lineEditSuma->text()+"_";
         QByteArray byteArray=trimite.toUtf8();
         char* charArray=byteArray.data();
         QString verificare=conexiune.connectServer(charArray);
         if(verificare=="0")
             ui->labelInformatie->setText("<font color='red'>Nu exista acest ID!</font>");
         else
             ui->labelInformatie->setText("<font color='green'>Amenda trimisa cu succes!</font>");
    }
}

