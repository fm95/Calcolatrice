#ifndef QUADRATO_H
#define QUADRATO_H

#include "rettangolo.h"

class Quadrato: public Rettangolo
{
public:
    Quadrato(QString, vector<Vertice> &);
    Quadrato* clone() const override;

    double getPerimetro()const override;
    double getArea() const override;

    double getLato()const; // overloading
    double getApotema()const;

private:
    void print(std::ostream &) const override;
    friend ostream& operator<<(ostream&, const Quadrato&);
};

ostream& operator<<(ostream&, const Quadrato&);

#endif // QUADRATO_H
