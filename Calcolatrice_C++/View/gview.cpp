#include "gview.h"
#include "gscene.h"
#include "calcolatrice.h"

GView::GView(Calcolatrice *parent) : calc(parent)
{
    setAttribute( Qt::WA_DeleteOnClose);
    setRenderHint(QPainter::Antialiasing);
    scale(4,4);

    sc = new GScene(this);
    setScene(sc);
    scene()->setParent(this);
}

GView::~GView()
{
    delete sc;
    destroyed(this);
}

void GView::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(sc->items().size()>1) // altrimenti ci sono solo gli assi
    {
        QPointF p = event->pos();
        double x = (double)(p.x()/4-7); // vengono 'scalati' alla scene
        double y = (double)(p.y()/4-5.4); // scene->scale(4,4) + margini
        p.setX(x); p.setY(y);
        calc->cerca(*this, p);
    }
}

