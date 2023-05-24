#ifndef FEREASTRAVIZUALIZAREIBAN0URI_H
#define FEREASTRAVIZUALIZAREIBAN0URI_H

#include <QDialog>
#include "fereastralogin.h"


namespace Ui {
class fereastraVizualizareIBAN0uri;
}

class fereastraVizualizareIBAN0uri : public QDialog
{
    Q_OBJECT

public:
    explicit fereastraVizualizareIBAN0uri(fereastraLogin* p,QString v,QWidget *parent = nullptr);
    ~fereastraVizualizareIBAN0uri();

private slots:
    void on_pushButton_clicked();

private:
    Ui::fereastraVizualizareIBAN0uri *ui;
    fereastraLogin* parent;
};

#endif // FEREASTRAVIZUALIZAREIBAN0URI_H
