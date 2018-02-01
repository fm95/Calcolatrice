#ifndef RETTANGOLO_H
#define RETTANGOLO_H

#include "quadrilatero.h"

class Rettangolo: public Quadrilatero
{
public:
    Rettangolo(QString, vector<Vertice> &);
    Rettangolo* clone() const override;

    double getPerimetro()const override;
    double getArea() const override;
    double getSommaAngoli() const override;

    double getAngolo()const; //overloading
    double getDiagolale() const; //overloading

private:
    void print(std::ostream &) const override;
    friend ostream& operator<<(ostream&, const Rettangolo&);
};

ostream& operator<<(ostream&, const Rettangolo&);

#endif // RETTANGOLO_H
