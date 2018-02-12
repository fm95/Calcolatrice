#ifndef POLIGONIC_H
#define POLIGONIC_H

#include <QGraphicsPolygonItem>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class GScene;

class poligoniC : public QGraphicsPolygonItem
{
public:
    poligoniC(QString, QPolygonF, GScene *parent = 0);

    QString getNome() const;
    QPolygonF getPol() const;

    QRectF boundingRect() const override;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *) override;

private:
    GScene *sc;

    QString nome;
    QPolygonF pol;
};

#endif // POLIGONIC_H
