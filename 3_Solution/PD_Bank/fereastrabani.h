#ifndef FEREASTRABANI_H
#define FEREASTRABANI_H

#include <QDialog>
#include "conectare.h"
#include "fereastralogin.h"
namespace Ui {
class fereastraBani;
}

class fereastraBani : public QDialog
{
    Q_OBJECT

public:
    explicit fereastraBani(fereastraLogin* p,QWidget *parent = nullptr);
    ~fereastraBani();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::fereastraBani *ui;
    fereastraLogin* parent;
    conectare conexiune;
};

#endif // FEREASTRABANI_H
