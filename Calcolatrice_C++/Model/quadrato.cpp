#include "quadrato.h"

Quadrato::Quadrato(QString s, const vector<Vertice> &v) : Rettangolo(s, v){}

Quadrato* Quadrato::clone() const
{
    return new Quadrato(*this);
}

double Quadrato::getPerimetro() const
{
    double l = distanza(Vertici[0], Vertici[1]);
    return l*4;
}

double Quadrato::getArea() const
{
    double l = distanza(Vertici[0], Vertici[1]);
    return l*l;
}

double Quadrato::getLato() const
{
    return distanza(Vertici[0], Vertici[1]);
}

double Quadrato::getApotema() const
{
    return 0.5*getLato();
}

ostream &operator<<(ostream &os, const Quadrato &q)
{
    q.print(os);
    return os;
}
