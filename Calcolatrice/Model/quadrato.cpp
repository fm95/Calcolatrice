#include "quadrato.h"

Quadrato::Quadrato(QString s, vector<Vertice> &v) : Rettangolo(s, v){}

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

void Quadrato::print(std::ostream &os) const
{
    os<<getNome().toStdString()<<": ";
    for(int i=0; i<4; ++i)
    {
        os<<"{("<<Vertici[i].Punto::getX()<<","<<Vertici[i].Punto::getY()<<") ";
        os<<Vertici[i].getInfo()<<"}";
        i!=3? os<<" -> " : os<<"";
    }
}

ostream &operator<<(ostream &os, const Quadrato &q)
{
    q.print(os);
    return os;
}
