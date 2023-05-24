#include "fereastrainregistrare.h"
#include "ui_fereastrainregistrare.h"
#include <QMessageBox>
fereastraInregistrare::fereastraInregistrare(MainWindow* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fereastraInregistrare)
{
    ui->setupUi(this);
    this->parent=p;
}

fereastraInregistrare::~fereastraInregistrare()
{
    delete ui;
}

void fereastraInregistrare::on_pushButtonInregistrare_clicked()
{
    int error=0;
    QString telefon =ui->lineEditTelefon->text();
    QString cnp=ui->lineEditCNP->text();
    QString string = "1_"+ui->lineEditNume->text() + "_" + ui->lineEditPrenume->text() + "_" + ui->lineEditCNP->text() + "_" + ui->lineEditUsername->text()+"_"+ui->lineEditParola->text()+"_"+ui->lineEditTelefon->text()+"_"+ui->lineEditMail->text()+"_";
    QByteArray byteArray=string.toUtf8();
    char* charArray=byteArray.data();

    if(telefon.left(2) != "07" ||  telefon.length()!=10)
        error=1;
    if(cnp.length() != 13)
        error=2;
    if(ui->lineEditCNP->text().length()==0 || ui->lineEditMail->text().length()==0 || ui->lineEditNume->text().length()==0 || ui->lineEditPrenume->text().length()==0 || ui->lineEditParola->text().length()==0 || ui->lineEditUsername->text().length()==0 || ui->lineEditTelefon->text().length()==0)
        error=-1;
    if(error==0)
    {
    QString verificare=conexiune.connectServer(charArray);
    if(verificare=="0")
    {
        ui->labelInformatie->setText("<font color='purple'>Numele de utilizator/telefonul/CNP-ul este deja folosit!</font>");
    }
    else {
        close();
        this->parent->show();
    }
    }


    if(error==1)
        ui->labelInformatie->setText("<font color='purple'>Numarul de telefon este invalid!</font>");
    if(error==2)
        ui->labelInformatie->setText("<font color='purple'>CNP-ul este invalid!</font>");
    if(error==-1)
        ui->labelInformatie->setText("<font color='purple'>Toate campurile sunt obligatorii!</font>");

}


void fereastraInregistrare::on_pushButtonInapoi_clicked()
{
    close();
    this->parent->show();
}

