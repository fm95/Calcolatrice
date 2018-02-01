#ifndef TRIANGOLO_H
#define TRIANGOLO_H

#include "poligonoconvesso.h"

class Triangolo: public PoligonoConvesso
{
public:
    Triangolo(QString, vector<Vertice>);
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

protected:
    static const unsigned int numLati;

private:
    void print(std::ostream &) const override;
    friend ostream& operator<<(ostream&, const Triangolo&);
};

ostream& operator<<(ostream&, const Triangolo&);

#endif // TRIANGOLO_H
