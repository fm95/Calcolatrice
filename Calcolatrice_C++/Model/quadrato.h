#ifndef QUADRATO_H
#define QUADRATO_H

#include "rettangolo.h"

class Quadrato final: public Rettangolo
{
    friend ostream& operator<<(ostream&, const Quadrato&);
public:
    Quadrato(QString, const vector<Vertice> &);
    Quadrato* clone() const override;

    double getPerimetro()const override;
    double getArea() const override;

    double getLato()const; // overloading
    double getApotema()const; // overloading

};

ostream& operator<<(ostream&, const Quadrato&);

#endif // QUADRATO_H
