#ifndef VERTICE_H
#define VERTICE_H

#include "punto.h"
#include <typeinfo>
#include <math.h>

using std::pow;
using std::atan2;

class Vertice: public Punto
{
public:
    Vertice();
    Vertice(const Punto&, double =0);

    double getInfo()const;
    double getGradiAngolo()const;

    void setInfo(double i);
    void setGradi(double g);

    bool operator==(const Punto&)const override;
    bool operator!=(const Punto&)const override;

private:
    double info, gradiAngolo;

};

double AngoloVertici(const Vertice&, const Vertice&, const Vertice &);

ostream& operator << (ostream&, const Vertice&);

#endif // VERTICE_H
