#include "assi.h"

#include <string>

Assi::Assi(sceneTriangolo *parent):scene(parent){}

void Assi::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    Assi X e Y
    painter->setPen(QPen(Qt::black, 0.5, Qt::SolidLine));
    AsseX.setLine(-3,0, 140,0); // da definire in base alla larghezza di info
    AsseY.setLine(0,-3, 0,110);
    painter->drawLine(AsseX);
    painter->drawLine(AsseY);

//    Arrow
    painter->drawPolygon(QPolygonF() << QPointF(140,-2) << QPointF(144,0) << QPointF(140,2)); // X
    painter->drawPolygon(QPolygonF() << QPointF(-2,110) << QPointF(0,114) << QPointF(2,110)); // Y

//    Scritta "Asse .."
    painter->setFont(QFont("Ubuntu", 4, 1));
    infoX = "X";
    infoY = "Y";
    painter->drawText(145, 2, infoX);
    painter->drawText(3, 114, infoY);

//    Info assi (ogni 5pt)
    painter->setFont(QFont("Ubuntu", 3));
    painter->drawText(QPoint(-3,-1), "0");
    painter->setFont(QFont("Ubuntu", 2));
    for(int i=5; i<140; i+=5) // X
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

