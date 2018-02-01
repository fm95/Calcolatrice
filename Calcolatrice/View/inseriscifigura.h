#ifndef INSERISCIFIGURA_H
#define INSERISCIFIGURA_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class inserisciFigura : public QWidget
{
    Q_OBJECT
public:
    explicit inserisciFigura(QWidget *parent = 0);
    void closeEvent(QCloseEvent *);
    virtual ~inserisciFigura();

signals:

public slots:

private:
    QPushButton* submit;
    QLabel *n; // nome
    QLabel *nLati; // # lati
//    lista punti

    void Layout();
    void clear();
};

#endif // INSERISCIFIGURA_H
