#ifndef CALCOLATRICE_H
#define CALCOLATRICE_H

#include <QDialog>
#include <QTabWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>

#include "viewtriangolo.h"
#include "viewquadrilatero.h"
#include "viewrettangolo.h"
#include "viewquadrato.h"

namespace Ui {
    class Calcolatrice;
}

class Calcolatrice : public QDialog
{
    Q_OBJECT

public:
    explicit Calcolatrice(QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);
    ~Calcolatrice();

    void disabilitaView();
    void abilitaView();

private slots:
    void on_eliminaFigura_pressed();

    void on_eliminaVertice_pressed();
    void on_Somma_pressed();

    void on_inserisciFigura_pressed();

private:
    Ui::Calcolatrice *ui;

    QVBoxLayout lt;
    viewTriangolo* vT;

    QVBoxLayout lQr;
    viewQuadrilatero *vQr;

    QVBoxLayout lR;
    viewRettangolo *vR;

    QVBoxLayout lQ;
    viewQuadrato *vQ;


    QGraphicsView *getView();
    void nonSelez();
};

#endif // CALCOLATRICE_H
