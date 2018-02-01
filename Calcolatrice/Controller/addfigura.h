#ifndef ADDFIGURA_H
#define ADDFIGURA_H

#include <QObject>

#include "View/calcolatrice.h"
#include "Model/poligonoconvesso.h"
#include "View/inseriscifigura.h"

class addFigura: public QObject
{
    Q_OBJECT
public:
    explicit addFigura(Calcolatrice *, inserisciFigura *, QObject *parent = 0);

public slots:
    void add(); // const TIPO&
    void close();

private:
    Calcolatrice *calc;
    inserisciFigura *view;

};

#endif // ADDFIGURA_H
