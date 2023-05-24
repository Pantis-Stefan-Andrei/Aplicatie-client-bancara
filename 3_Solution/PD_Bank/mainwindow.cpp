
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

#include "fereastrainregistrare.h"
#include "fereastralogin.h"
#include "fereastraadmin.h"

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

void MainWindow::on_pushButtonInregistrare_clicked()
{
    close();
    fereastraInregistrare* fereastrainregistrare=new fereastraInregistrare(this);
    fereastrainregistrare->resize(800,500);
    fereastrainregistrare->setWindowTitle("PD Bank");
    fereastrainregistrare->show();
}

void delay(int secs)
{
    QTime dieTime=QTime::currentTime().addSecs(secs);
    while(QTime::currentTime()<dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}

void MainWindow::on_pushButtonLogin_clicked()
{
    int admin=0;
    if(ui->lineEditUsername->text()=="admin" && ui->lineEditParola->text()=="admin")
    {
        close();
        fereastraAdmin* fereastraadmin=new fereastraAdmin(this);
        fereastraadmin->resize(800,500);
        fereastraadmin->setWindowTitle("PD Bank");
        fereastraadmin->show();
        admin=1;
    }
    if(admin ==0)
    {
    QString string="5_"+ui->lineEditUsername->text()+"_"+ui->lineEditParola->text()+"_";
    QByteArray byteArray=string.toUtf8();
    char* charArray=byteArray.data();
    QString verificare=conexiune.connectServer(charArray);
    if(verificare=="0")
    {
        ui->labelInformatie->setText("<font color='red'>Nume de utilizator sau parola gresita!</font>");
    }
    else
    {

        ui->labelInformatie->setText("<font color='green'>Logare reusita!</font>");
        delay(2);
        ui->labelInformatie->setText("");
        close();
        fereastraLogin* fereastralogin=new fereastraLogin(this,verificare);
        fereastralogin->resize(800,500);
        fereastralogin->setWindowTitle("PD Bank");
        fereastralogin->show();
    }
    }
}



