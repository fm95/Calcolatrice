#ifndef INSERTFIGURA_H
#define INSERTFIGURA_H

#include <QDialog>
#include <QMessageBox>
#include <vector>

#include "Controller/graphcontroller.h"
#include "Model/poligonoconvesso.h"

using std::vector;
class GraphController;

namespace Ui {
    class insertFigura;
}

class insertFigura : public QDialog
{
    Q_OBJECT
public:
    insertFigura(GraphController *, QWidget *parent = 0); // Inserisce nuova figura
    insertFigura(QString, GraphController *, QWidget *parent = 0); // Inserisce vertice
    insertFigura(unsigned int, QString, GraphController *, QWidget *parent = 0); // Elimina vertice
    insertFigura(QString, double i, GraphController *, QWidget *parent = 0); // Modifica info
    insertFigura(QString, double i, double j, GraphController *, QWidget *parent = 0); // Diagonale

    ~insertFigura();
    void closeEvent(QCloseEvent *event);

private slots:
    void Conferma_pressed();
    void Avanti_pressed();

private:
    Ui::insertFigura *ui;
    GraphController *ct; // controller

    vector<Vertice> buildV; // vertici del nuovo poligono
    double pos = -1; // posizione in cui eliminare o modificare
    double inf = -1; // nuovo campo info
    QString Nome = ""; // nome della figura da cambiare

    // controlli sugli input del form
    bool checkNome();
    bool checknLati();
    bool checkVertice();
};

#endif // INSERTFIGURA_H
