#include "vertice.h"

Vertice::Vertice(): Punto(), info(0), gradiAngolo(0){}

Vertice::Vertice(const Punto &p, double i): Punto(p), info(i), gradiAngolo(0){}

double Vertice::getInfo()const
{
    return info;
}

double Vertice::getGradiAngolo()const
{
    return gradiAngolo;
}

void Vertice::setGradi(double g)
{
    if(g>=0)
        gradiAngolo=g;
}

void Vertice::setInfo(double i)
{
    info = i;
}

bool Vertice::operator==(const Punto& p)const
{
    if(typeid(p)==typeid(const Vertice&) && Punto::operator==(p))
    {
        const Vertice& v = static_cast<const Vertice&>(p);
        return info==v.info && gradiAngolo==v.gradiAngolo;
    }
    else
        return false;
}

bool Vertice::operator!=(const Punto& p)const
{
    if(typeid(p)!=typeid(const Vertice&) && Punto::operator !=(p))
    {
        const Vertice& v = static_cast<const Vertice&>(p);
        return info!=v.info || gradiAngolo!=v.gradiAngolo;
    }
    else
        return false;
}

double AngoloVertici(const Vertice &a, const Vertice &b, const Vertice &c)
{ // Calcola l'angolo del vertice B, compreso tra A e C
    Punto ab( b.getX() - a.getX(), b.getY() - a.getY() );
    Punto cb( b.getX() - c.getX(), b.getY() - c.getY() );

    double dot = (ab.getX() * cb.getX() + ab.getY() * cb.getY() );
    double cross = (ab.getX() * cb.getY() - ab.getY() * cb.getX());

    double alpha = atan2(cross, dot);
    return (alpha * 180 / M_PI);
}

ostream& operator << (ostream& os, const Vertice& v)
{
    Punto p = v;
    return os<< "Vertice: (" << p.getX() << "," << p.getY()
             << ") " << v.getInfo()
             << " [" << v.getGradiAngolo() <<"°]";
}
