#ifndef CALCOLATRICE_H
#define CALCOLATRICE_H

#include <QDialog>
#include <QTabWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QCloseEvent>
#include <QGraphicsView>

#include "poligonic.h"
#include "Controller/graphcontroller.h"
#include "insertfigura.h"
#include "Model/poligonoconvesso.h"
#include "gscene.h"
#include "insertfigura.h"
#include "gview.h"

class GView;
class GraphController;
class insertFigura;
class poligoniC;
class GScene;

namespace Ui {
    class Calcolatrice;
}

class Calcolatrice : public QDialog
{
    Q_OBJECT

public: 
    explicit Calcolatrice(QWidget *parent = 0);
    virtual ~Calcolatrice();

// Metodi di utilita'
    void deseleziona();
    void cerca(const GView &, const QPointF);
    void infoPrint(QString) const;
    void errorPrint(QString ="") const;

// Disegnano i poligoni nella scene
    void addTriangolo(poligoniC *);
    void addQuadrilatero(poligoniC *);
    void addRettangolo(poligoniC *);
    void addQuadrato(poligoniC *);

protected:
    void closeEvent(QCloseEvent *event) override;
    void mousePressEvent(QMouseEvent *) override;

private slots:
    void inserisciFigura_pressed();
    void eliminaFigura_pressed();
    void eliminaTutto_pressed();

    void inserisciVertice_pressed();
    void eliminaVertice_pressed();
    void modificaInfo_pressed();

    void Max_pressed();
    void Min_pressed();
    void AVG_pressed();
    void Somma_pressed();
    void Sottrazione_pressed();
    void Apotema_pressed();

private:
    Ui::Calcolatrice *ui;

    GraphController *ct; // controller
    QMessageBox* msg; // messaggio info

    QVBoxLayout lt; // triangolo
    GView *vT;
    QVBoxLayout lQr; // quadrilatero
    GView *vQr;
    QVBoxLayout lR; // rettangolo
    GView *vR;
    QVBoxLayout lQ; // quadrato
    GView *vQ;

    QList<poligoniC*> list; // lista di tutti i poligoni disegnati
    poligoniC *pS; // figura selezionata

    void elimina(QString); // elimina un poligono da list
    void eliminaList(); // elimina tutti i poligoni da list
    void seleziona(poligoniC *&); // seleziona il poligono che viene creato
};

#endif // CALCOLATRICE_H
