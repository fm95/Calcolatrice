#ifndef PUNTO_H
#define PUNTO_H

#include <cmath>
#include <iostream>

using std::ostream;
using std::sqrt;

class Punto
{
public:
    Punto();
    Punto(double, double);

    double getX()const;
    double getY()const;
    void setX(double);
    void setY(double);

    virtual bool operator==(const Punto&)const;
    virtual bool operator!=(const Punto&)const;

private:
    double x, y;

};

double distanza(const Punto&, const Punto&);
double determinante(const Punto&, const Punto&);

ostream& operator << (ostream&, const Punto&);

#endif // PUNTO_H
