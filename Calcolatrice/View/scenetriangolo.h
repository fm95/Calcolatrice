#ifndef SCENETRIANGOLO_H
#define SCENETRIANGOLO_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "assi.h"
#include "itemtriangolo.h"

class Assi;
class viewTriangolo;
class QGraphicsSceneMouseEvent;
class itemTriangolo;

class sceneTriangolo : public QGraphicsScene
{
public:
    explicit sceneTriangolo(viewTriangolo* parent=0);
    void addPolygon(const QPolygonF &polygon, const QPen &pen, const QBrush &brush);

private:
    Assi* assi; 

    QList<itemTriangolo*> lt;

    //    InfoTriangoli *info; // QGraphicsTextItem
};

#endif // SCENETRIANGOLO_H
