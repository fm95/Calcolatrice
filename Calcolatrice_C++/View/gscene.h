#ifndef GSCENE_H
#define GSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class GView;
class Assi;

class GScene : public QGraphicsScene
{
public:
    explicit GScene(GView *parent = 0);
    ~GScene();

private:
    GView *view;
    Assi *assi;

};

#endif // GSCENE_H
