#ifndef QUADRILATERO_H
#define QUADRILATERO_H

#include "poligonoconvesso.h"

class Quadrilatero: public PoligonoConvesso
{
public:
    Quadrilatero(QString, vector<Vertice> &);
    Quadrilatero* clone() const override;

    double getPerimetro()const override;
    double getArea() const override;
    double getSommaAngoli() const override;
    unsigned int getNumLati() const override;

    double getDiagolale(unsigned int, unsigned int) const;

    bool operator<(const Figura&) const override;
    bool operator>(const Figura&) const override;

protected:
    static const unsigned int numLati;

private:
    void print(std::ostream &) const override;
    friend ostream& operator<<(ostream&, const Quadrilatero&);
};

ostream& operator<<(ostream&, const Quadrilatero&);

#endif // QUADRILATERO_H
