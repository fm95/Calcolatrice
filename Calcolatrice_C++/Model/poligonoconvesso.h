#ifndef POLIGONO_H
#define POLIGONO_H

#include <algorithm>
#include <vector>
#include <stdexcept>

#include "figura.h"
#include "vertice.h"

using std::abs;
using std::ostream;
using std::vector;
using std::invalid_argument;

class PoligonoConvesso: public Figura
{
public:
    PoligonoConvesso(QString, const vector<Vertice> &, const unsigned int);

    virtual PoligonoConvesso* clone() const =0;
    virtual double getSommaAngoli() const =0;
    virtual unsigned int getNumLati()const =0;

    double getLato(double, double =-1)const; // info & pos (se sono tutte uguali)
    double getAngolo(double, double =-1)const; // info & pos (se sono tutte uguali)
    int getNumDiagonali() const;
    bool isEquiangolo() const;
    bool isEquilatero() const;
    bool isRegolare() const;

    void modificaInfo(unsigned int, double); // pos & nuovoInfo
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

    vector<Vertice>& getVertici();

protected:
    vector<Vertice> Vertici;
    static double calcolaAngolo(const vector<Vertice> &, unsigned int);
    void print(ostream &) const override;

private:
    static unsigned int limiteVertici; // si puo' costruire un Poligono con al massimo 20 vertici
    static PoligonoConvesso* costruisci(QString, const vector<Vertice> &);
};

int WindingNumberInclusion(const Vertice&, const vector<Vertice> &);
double isLeft(const Vertice &, const Vertice &, const Vertice &);

#endif // POLIGONO_H
