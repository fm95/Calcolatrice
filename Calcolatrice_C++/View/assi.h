#ifndef ASSI_H
#define ASSI_H

#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QPainter>
#include <string>
#include <math.h>

class GScene;

// Assi del piano cartesiano
class Assi : public QGraphicsLineItem
{
public:
    Assi(GScene *parent=0);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

private:
    GScene* sc; // scene su cui disegnare gli assi

    QLineF AsseX;
    QLineF AsseY;
    QString infoX;
    QString infoY;
};

#endif // ASSI_H
