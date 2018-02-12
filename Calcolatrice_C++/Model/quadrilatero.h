#ifndef QUADRILATERO_H
#define QUADRILATERO_H

#include "poligonoconvesso.h"

class Quadrilatero: public PoligonoConvesso
{
    friend ostream& operator<<(ostream&, const Quadrilatero&);
public:
    Quadrilatero(QString, const vector<Vertice> &);
    Quadrilatero* clone() const override;

    double getPerimetro()const override;
    double getArea() const override;
    double getSommaAngoli() const override final;
    unsigned int getNumLati() const override final;

    double getDiagolale(unsigned int, unsigned int) const; // pos1 & pos2

    bool operator<(const Figura&) const override final;
    bool operator>(const Figura&) const override final;
    string toString() const override final;

protected:
    static const unsigned int numLati;

};

ostream& operator<<(ostream&, const Quadrilatero&);

#endif // QUADRILATERO_H
