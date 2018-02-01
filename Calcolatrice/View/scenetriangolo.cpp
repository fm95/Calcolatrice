#include "scenetriangolo.h"

sceneTriangolo::sceneTriangolo(viewTriangolo *parent) : QGraphicsScene(parent)
{       
//    Piano Cartesiano
    assi = new Assi(this);
    addItem(assi);

}

void sceneTriangolo::addPolygon(const QPolygonF &polygon, const QPen &pen, const QBrush &brush)
{
    // se non collide con gli altri poligoni gia' presenti

//    addPolygon(polygon);

}


