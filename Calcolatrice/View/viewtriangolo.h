#ifndef VIEWTRIANGOLO_H
#define VIEWTRIANGOLO_H

#include <QGraphicsView>
#include "scenetriangolo.h"

class sceneTriangolo;

class viewTriangolo : public QGraphicsView
{
    Q_OBJECT

public:
    explicit viewTriangolo(QWidget *parent = 0);

public slots:
        void mousePressEvent(QMouseEvent * e);

private:
    sceneTriangolo* sT;

};

#endif // VIEWTRIANGOLO_H
