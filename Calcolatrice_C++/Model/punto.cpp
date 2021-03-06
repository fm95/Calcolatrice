#include "punto.h"

Punto::Punto(): x(0), y(0){}

Punto::Punto(double sx, double sy):x(sx), y(sy){}

double Punto::getX()const
{
    return x;
}

double Punto::getY()const
{
    return y;
}

void Punto::setX(double sx) // il controllo dipende dal piano della view
{
    x=sx;
}

void Punto::setY(double sy) // il controllo dipende dal piano della view
{
    y=sy;
}

bool Punto::operator==(const Punto&p)const
{
    return x==p.x && y==p.y;
}

bool Punto::operator!=(const Punto& p)const
{
    return x!=p.x || y!=p.y;
}

string Punto::toString() const
{
    stringstream buffer;
    buffer << *this;
    return buffer.str();
}

double distanza(const Punto& p1, const Punto& p2)
{
    const double dX = ((p1.getX()-p2.getX())*(p1.getX()-p2.getX()));
    const double dY = ((p1.getY()-p2.getY())*(p1.getY()-p2.getY()));

    return sqrt( dX + dY );
}

double determinante(const Punto &p1, const Punto &p2)
{
    return (p1.getX() * p2.getY()) - (p1.getY() * p2.getX());
}

ostream& operator << (ostream& os, const Punto &p)
{
    return os<<"("<<p.getX()<<","<<p.getY()<<")";
}

