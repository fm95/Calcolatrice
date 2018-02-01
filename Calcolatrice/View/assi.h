#ifndef ASSI_H
#define ASSI_H

#include <math.h>
#include <QGraphicsLineItem>

#include "viewtriangolo.h"

class viewTriangolo;

class sceneTriangolo;

class Assi : public QGraphicsLineItem
{
public:
    Assi(sceneTriangolo* parent=0);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    sceneTriangolo* scene;

    QLineF AsseX;
    QLineF AsseY;
    QString infoX;
    QString infoY;
};

#endif // ASSI_H
