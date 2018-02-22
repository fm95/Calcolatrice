#include "assi.h"
#include "gscene.h"

Assi::Assi(GScene *parent) : sc (parent)
{
    setFlag(QGraphicsItem::ItemIsSelectable, false);
    setFlag(QGraphicsItem::ItemIsFocusable, false);
}

QRectF Assi::boundingRect() const { return QRect(); }

void Assi::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
//    Assi X e Y
    painter->setPen(QPen(Qt::black, 0.5, Qt::SolidLine));
    AsseX.setLine(-3,0, 165,0);
    AsseY.setLine(0,-3, 0,110);
    painter->drawLine(AsseX);
    painter->drawLine(AsseY);

//    Arrow
    painter->drawPolygon(QPolygonF() << QPointF(165,-2) << QPointF(170,0) << QPointF(165,2)); // X
    painter->drawPolygon(QPolygonF() << QPointF(-2,110) << QPointF(0,114) << QPointF(2,110)); // Y

//    Scritta "Asse .."
    painter->setFont(QFont("Ubuntu", 4, 1));
    infoX = "X";
    infoY = "Y";
    painter->drawText(172, 2, infoX);
    painter->drawText(3, 114, infoY);

//    Info assi (ogni 5pt)
    painter->setFont(QFont("Ubuntu", 3));
    painter->drawText(QPoint(-3,-1), "0");
    painter->setFont(QFont("Ubuntu", 2));
    for(int i=5; i<165; i+=5) // X
    {
        painter->drawLine(i,-1, i,1);
        if(i%10==0)
            painter->drawText(QPoint(i-2,-2), QString::number(i));
        if(i<110)
        {
            painter->drawLine(-1,i, 1,i);
            if(i%10==0)
                painter->drawText(QPoint(-6,i+1.5), QString::number(i));
        }
    }
}

