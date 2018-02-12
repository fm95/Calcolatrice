#ifndef PUNTO_H
#define PUNTO_H

#include <cmath>
#include <ostream>
#include <string>
#include <sstream>

using std::ostream;
using std::sqrt;
using std::string;
using std::stringstream;

class Punto
{
public:
    Punto();
    Punto(double, double);
    virtual ~Punto() = default;

    double getX()const;
    double getY()const;
    void setX(double);
    void setY(double);

    virtual bool operator==(const Punto&)const;
    virtual bool operator!=(const Punto&)const;
    virtual string toString() const;

private:
    double x, y;

};

double distanza(const Punto&, const Punto&);
double determinante(const Punto&, const Punto&);

ostream& operator << (ostream&, const Punto&);

#endif // PUNTO_H
