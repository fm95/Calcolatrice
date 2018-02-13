#include "gview.h"
#include "gscene.h"
#include "calcolatrice.h"
#include "poligonic.h"

GView::GView(Calcolatrice *parent) : calc(parent)
{
    setAttribute( Qt::WA_DeleteOnClose);
    setRenderHint(QPainter::Antialiasing);
    scale(4,4); // zoom della view

    sc = new GScene(this);
    setScene(sc);
    scene()->setParent(this); // viene gia' impostato nella costruzione
}

GView::~GView()
{
    delete sc;
    destroyed(this);
}

void GView::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(sc->items().size()>1) // altrimenti ci sono solo gli assi, che ovviamente non devo considerare
    {
        QPointF p = event->pos(); // posizione dove ho clikkate
        double x = (double)(p.x()/4-7); // vengono 'scalati' alla scene
        double y = (double)(p.y()/4-5.4); // scene->scale(4,4) + margini
        p.setX(x); p.setY(y);
        calc->cerca(*this, p);
        // cerco se nella scene della view corrente c'e' un poligono che contiene quel punto
    }
}

