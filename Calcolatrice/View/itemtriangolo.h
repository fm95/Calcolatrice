#ifndef ITEMTRIANGOLO_H
#define ITEMTRIANGOLO_H

#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>

class itemTriangolo : public QGraphicsPolygonItem
{
public:
    itemTriangolo(QGraphicsItem *parent);
    QPolygonF getPolygon() const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *);

private:
    QPolygonF tr;
    QString name;

};

#endif // ITEMTRIANGOLO_H
