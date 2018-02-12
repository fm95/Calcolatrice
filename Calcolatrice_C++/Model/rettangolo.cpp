#include "rettangolo.h"

Rettangolo::Rettangolo(QString s, const vector<Vertice> &v) : Quadrilatero(s, v){}

Rettangolo *Rettangolo::clone() const
{
    return new Rettangolo(*this);
}

double Rettangolo::getPerimetro() const
{
    double a = distanza(Vertici[0], Vertici[1]);
    double b = distanza(Vertici[1], Vertici[2]);

    return (a+b)*2;
}

double Rettangolo::getArea() const
{
    double a = distanza(Vertici[0], Vertici[1]);
    double b = distanza(Vertici[1], Vertici[2]);

    return a*b;
}

double Rettangolo::getAngolo() const
{
    return calcolaAngolo(Vertici,0);
}

double Rettangolo::getDiagolale() const
{
    return distanza(Vertici[0], Vertici[2]);
}

void Rettangolo::print(std::ostream &os) const
{ // non stampo gli angoli, perche' e' ovvio che sono di 90°
    os<<getNome().toStdString()<<": ";
    for(int i=0; i<4; ++i)
    {
        os<<"("<<Vertici[i].Punto::getX()<<","<<Vertici[i].Punto::getY()<<") ";
        os<<Vertici[i].getInfo();
        i!=3? os<<" > " : os<<"";
    }
}

ostream &operator<<(ostream &os, const Rettangolo &q)
{
    q.print(os);
    return os;
}
