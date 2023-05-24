
#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <iostream>
#include<Qstring>
using namespace std;




class Utilizator
{
    QString nume;
    QString prenume;
    QString CNP;
    QString telefon;
    QString mail;
    QString utilizator;
    QString parola;
    QString ID_Util;
    QString tipul;
    QString sold;
public:
    void printeaza();
    Utilizator();
    QString getNume();
    Utilizator(QString n,QString p,QString c,QString t,QString m,QString u,QString par,QString ID);
    Utilizator(QString ID,QString u, QString p);
    QString getID() {    return ID_Util;  }
    QString setSold(QString S){sold=S;}
};

#endif // UTILIZATOR_H
