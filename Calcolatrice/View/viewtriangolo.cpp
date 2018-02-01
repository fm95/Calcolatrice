#include "viewtriangolo.h"

viewTriangolo::viewTriangolo(QWidget *parent): QGraphicsView(parent)
{
    setRenderHint(QPainter::Antialiasing);
    setAutoFillBackground(true);

    scale(4,4);

    sT = new sceneTriangolo(this);
    setScene(sT);
    sT->setSceneRect(QRectF(0,0, 170, 110));

    //sT->setSceneRect(QRectF(1, 0, 762/4, 550/4));
}

void viewTriangolo::mousePressEvent(QMouseEvent *e)
{

}
