#ifndef RETTANGOLO_H
#define RETTANGOLO_H

#include "quadrilatero.h"

class Rettangolo: public Quadrilatero
{
    friend ostream& operator<<(ostream&, const Rettangolo&);
public:
    Rettangolo(QString, const vector<Vertice> &);
    Rettangolo* clone() const override;

    double getPerimetro()const override;
    double getArea() const override;

    double getAngolo()const; //overloading
    double getDiagolale() const; //overloading

protected:
    void print(std::ostream &) const override;

};

ostream& operator<<(ostream&, const Rettangolo&);

#endif // RETTANGOLO_H
