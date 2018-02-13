#include "poligonic.h"
#include "poligonic.h"
#include "gscene.h"

poligoniC::poligoniC(QString n, QPolygonF p, GScene *parent) :
    sc(parent),
    nome(n),
    pol(p)
{
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFillRule(Qt::WindingFill);
}

QString poligoniC::getNome() const
{
    return nome;
}

QPolygonF poligoniC::getPol() const
{
    return pol;
}

QRectF poligoniC::boundingRect() const
{
    return pol.boundingRect();
}

void poligoniC::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen pen(Qt::black);
    pen.setWidthF(0.8);
    QBrush b(Qt::NoBrush);

    painter->setBrush(b);
    painter->setPen(pen);

    painter->drawConvexPolygon(pol);
}

