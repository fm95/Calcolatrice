#ifndef GRAPHCONTROLLER_H
#define GRAPHCONTROLLER_H

#include <QList>
#include <QTextStream>
#include <QCloseEvent>
#include <QPolygonF>

#include "View/insertfigura.h"
#include "View/calcolatrice.h"
#include "dati.h"

class Calcolatrice;

class GraphController
{
public:
    GraphController(Calcolatrice *);
    ~GraphController();

    void c_inserisciFigura();
    void c_addFigura(QString, const vector<Vertice> &);

    bool c_eliminaFigura(QString);
    bool c_eliminaTutto();

    void c_inserisciVertice(QString);
    void c_eliminaVertice(QString);
    void c_eliminaV(QString, QString, unsigned int);
    void c_modificaInfo(QString);
    void c_aggiornaInfo(QString, unsigned int, double);

    double c_getMax(QString) const;
    double c_getMin(QString) const;
    double c_getAVG(QString) const;
    double c_getSomma(QString) const;
    double c_getSottrazione(QString) const;
    double c_getApotema(QString) const;

    bool c_isRegolare(QString) const;
    void c_stampaFigura(QString);
    void c_enabledQd(bool);
    bool c_getUnicoNome(QString)const;
    PoligonoConvesso*& c_getPoligono(QString) const;
    vector<Vertice>& c_getVertici(QString);

private:
    Dati* dati; // model
    Calcolatrice *calc; // view principale
    insertFigura *ins; // view inserimento

    void c_costruisciQp(const PoligonoConvesso&, QString, QPolygonF);
};

#endif // GRAPHCONTROLLER_H
