#ifndef GVIEW_H
#define GVIEW_H

#include <QGraphicsView>
#include "poligonic.h"

class Calcolatrice;
class GScene;

class GView : public QGraphicsView
{
    Q_OBJECT
public:
    GView(Calcolatrice *parent = 0);
    ~GView();

protected:
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    Calcolatrice *calc;
    GScene *sc;

};

#endif // GVIEW_H
