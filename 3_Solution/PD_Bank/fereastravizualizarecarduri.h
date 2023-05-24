#ifndef FEREASTRAVIZUALIZARECARDURI_H
#define FEREASTRAVIZUALIZARECARDURI_H

#include <QDialog>
#include "fereastralogin.h"
namespace Ui {
class fereastravizualizareCarduri;
}

class fereastravizualizareCarduri : public QDialog
{
    Q_OBJECT

public:
    explicit fereastravizualizareCarduri(fereastraLogin* p, QString verificare,QWidget *parent = nullptr);
    ~fereastravizualizareCarduri();

private slots:
    void on_pushButton_clicked();

private:
    Ui::fereastravizualizareCarduri *ui;
    fereastraLogin* parent;
};

#endif // FEREASTRAVIZUALIZARECARDURI_H
