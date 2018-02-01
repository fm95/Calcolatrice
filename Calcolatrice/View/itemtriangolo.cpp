#include "itemtriangolo.h"

itemTriangolo::itemTriangolo(QGraphicsItem *parent) : QGraphicsPolygonItem(parent)
{
    setFlag(QGraphicsItem::ItemIsSelectable, true);


}

QPolygonF itemTriangolo::getPolygon() const
{
    return tr;
}

void itemTriangolo::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if (e->button() != Qt::LeftButton)
        return;
    else
    {

    }
}

