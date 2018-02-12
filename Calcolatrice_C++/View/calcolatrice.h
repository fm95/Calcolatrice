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
    void on_inserisciFigura_pressed();
    void on_eliminaFigura_pressed();
    void on_eliminaTutto_pressed();

    void on_inserisciVertice_pressed();
    void on_eliminaVertice_pressed();
    void on_modificaInfo_pressed();

    void on_Somma_pressed();
    void on_Sottrazione_pressed();

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
