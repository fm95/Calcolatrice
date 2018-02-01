#ifndef POLIGONO_H
#define POLIGONO_H

#include "figura.h"
#include "vertice.h"

#include <algorithm>
#include <vector>

#include <QVector>
#include <QtCore/qvector.h>

using std::abs;
using std::ostream;
using std::vector;

class PoligonoConvesso: public Figura
{
    friend PoligonoConvesso& operator+(PoligonoConvesso&, const PoligonoConvesso&);
    friend PoligonoConvesso& operator-(PoligonoConvesso&, const PoligonoConvesso&);
public:
    PoligonoConvesso(QString, vector<Vertice> &, const unsigned int);

    virtual PoligonoConvesso* clone() const =0;
    virtual double getSommaAngoli() const =0;
    virtual unsigned int getNumLati()const =0;

    double getLato(double, double =-1)const;
    double getAngolo(double, double =-1)const;
    int getNumDiagonali() const;
    bool isEquiangolo()const;
    bool isEquilatero()const;
    bool isRegolare()const;

    void modificaInfo(unsigned int, double);
    bool infoUguali()const;
    PoligonoConvesso* inserisciVertice(QString, Vertice &);
    PoligonoConvesso* eliminaVertice(QString, unsigned int);
    double Max()const;
    double Min()const;
    double AVG()const;
    double Somma()const;
    double Sottrazione()const;

    bool operator==(const PoligonoConvesso&) const;
    bool operator!=(const PoligonoConvesso&) const;

protected:
    vector<Vertice> Vertici;

private:
    static unsigned int limiteVertici; // si puo' costruire un Poligono con al massimo 20 vertici
    static bool controllaVertici(const vector<Vertice> &);
    static PoligonoConvesso* costruisci(QString, vector<Vertice> &);
    static int WindingNumberInclusion(const Vertice&, const vector<Vertice>&);
    static int isLeft(const Vertice &, const Vertice &, const Vertice &);

};

PoligonoConvesso& operator+(PoligonoConvesso&, const PoligonoConvesso&);
PoligonoConvesso& operator-(PoligonoConvesso&, const PoligonoConvesso&);

#endif // POLIGONO_H
