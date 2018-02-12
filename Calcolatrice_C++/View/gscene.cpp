#include "gscene.h"
#include "gview.h"
#include "assi.h"

GScene::GScene(GView *parent) : view(parent)
{   
//    Piano Cartesiano
    assi = new Assi(this);
    addItem(assi);
}

GScene::~GScene()
{
    QList<QGraphicsItem *> l = items();
    for(int i=0; i<l.size(); ++i)
        delete l.takeAt(i);
    clear();
    destroyed();
}

