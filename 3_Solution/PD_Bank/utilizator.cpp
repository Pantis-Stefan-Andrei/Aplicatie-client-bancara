
#include "utilizator.h"
#include <QDebug>

Utilizator::Utilizator()
{

}

Utilizator::Utilizator(QString ID,QString u, QString p)
{
    this->ID_Util=ID;
    this->utilizator=u;
    this->parola=p;
}

Utilizator::Utilizator(QString n,QString p,QString c,QString t,QString m,QString u,QString par,QString ID)
{
    this->nume=n;
    this->prenume=p;
    this->CNP=c;
    this->telefon=t;
    this->mail=m;
    this->utilizator=u;
    this->parola=par;
    this->ID_Util=ID;
}

void Utilizator::printeaza()
{
    qDebug() << this->ID_Util << " " << this->nume <<" "<<this->prenume << " " << this->telefon <<" " <<this->CNP<<" " << this->mail<<" "<<this->utilizator << " " << this->parola;

}

QString Utilizator::getNume()
{
    return this->nume;
}
