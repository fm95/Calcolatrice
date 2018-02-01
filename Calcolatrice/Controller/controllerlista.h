#ifndef CONTROLLERLISTA_H
#define CONTROLLERLISTA_H

#include "data.h"

class controllerLista
{
public:
    controllerLista() = default;
    controllerLista(QList<Figura*>);

    // tutti i qpushbutton


    QList<Figura*>& getList();

private:
    Data figure;

    // punt alla view
    // punt al model

};

#endif // CONTROLLERLISTA_H
