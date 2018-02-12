#ifndef TRIANGOLO_H
#define TRIANGOLO_H

#include "poligonoconvesso.h"

class Triangolo final: public PoligonoConvesso
{
    friend ostream& operator<<(ostream&, const Triangolo&);
public:
    Triangolo(QString, const vector<Vertice> &);
    Triangolo* clone() const override;

    double getPerimetro()const override;
    double getArea() const override;
    double getSommaAngoli() const override;
    unsigned int getNumLati()const override;

    double getApotema()const;
    bool isIsoscele()const;
    bool isScaleno()const;
    bool isRettangolo()const;
    bool isOttusangolo()const;
    bool isAcutangolo()const;

    bool operator<(const Figura&) const override;
    bool operator>(const Figura&) const override;
    string toString() const override;

protected:
    static const unsigned int numLati;

};

ostream& operator<<(ostream&, const Triangolo&);

#endif // TRIANGOLO_H
