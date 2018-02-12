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
    Vertice(double, double, double =0);
    Vertice(const Punto&, double =0);

    double getInfo()const;
    void setInfo(double i);

    bool operator==(const Punto&)const override;
    bool operator!=(const Punto&)const override;
    string toString() const override;

private:
    double info;

};

double AngoloVertici(const Vertice&, const Vertice&, const Vertice &); // angolo del vertice in mezzo

ostream& operator << (ostream&, const Vertice&);

#endif // VERTICE_H
