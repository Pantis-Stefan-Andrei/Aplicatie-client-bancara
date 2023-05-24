#ifndef FEREASTRAVIZUALIZARETRANZACTII_H
#define FEREASTRAVIZUALIZARETRANZACTII_H

#include <QDialog>
#include "fereastralogin.h"

namespace Ui {
class fereastraVizualizareTranzactii;
}

class fereastraVizualizareTranzactii : public QDialog
{
    Q_OBJECT

public:
    explicit fereastraVizualizareTranzactii(fereastraLogin* p, QString verificare,QWidget *parent = nullptr);
    ~fereastraVizualizareTranzactii();

private slots:
    void on_pushButton_clicked();

private:
    Ui::fereastraVizualizareTranzactii *ui;
    fereastraLogin* parent;
};

#endif // FEREASTRAVIZUALIZARETRANZACTII_H
