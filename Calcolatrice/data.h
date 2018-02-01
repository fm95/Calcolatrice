#ifndef DATA_H
#define DATA_H

#include <QList>

#include "Model/poligonoconvesso.h"

class Data
{
public:
    Data() = default;
    Data(QList<PoligonoConvesso*>);

    // get triangoli ecc.

    // operazioni
    void eliminaFigura();

private:
    QList<Figura*> list;
};

#endif // DATA_H



/*
void myClass::dataValidation()
{
//      validate data
    emit mySignal();
}
*/


