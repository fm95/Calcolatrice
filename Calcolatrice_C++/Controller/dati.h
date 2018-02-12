#ifndef DATI_H
#define DATI_H

#include <QList>
#include "Model/quadrato.h"
#include "Model/triangolo.h"
#include "Model/poligonoconvesso.h"

class Dati
{
public:
    Dati() = default;
    ~Dati();

    void costruisci(QString, const vector<Vertice> &);
    void eliminaFigura(QString);
    void eliminaTutto();

    void modInfo(QString, unsigned int, double);
    void insertVertice(QString, Vertice&);
    void deleteVertice(QString, unsigned int);

    double getMax(QString) const;
    double getMin(QString) const;
    double getAVG(QString) const;
    double getSomma(QString) const;
    double getSottrazione(QString) const;
    double getApotema(QString) const;

    bool nomeUnico(QString) const;
    PoligonoConvesso*& getPoligono(QString);

private:
    QList<PoligonoConvesso*> list;

};

#endif // DATI_H

