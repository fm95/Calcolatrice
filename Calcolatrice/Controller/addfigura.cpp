#include "addfigura.h"

addFigura::addFigura(Calcolatrice *c, inserisciFigura *i, QObject *parent):
    QObject(parent), calc(c), view(i)
{
    //calc->disabilita_view();

//    connect(view,SIGNAL(submitL(const info_opera&)),this,SLOT(add(const info_opera&)));
//    connect(view,SIGNAL(chiudi_aggiungi_Libro()),this,SLOT(chiudi_add_libro()));
}

void addFigura::add()
{
//    inserisciFigura();
//    calc->aggiorna_vista();
}

void addFigura::close()
{
//    calc->abilitaView();
    delete view;
}
