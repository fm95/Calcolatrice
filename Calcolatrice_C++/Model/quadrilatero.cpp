#include "quadrilatero.h"
#include "poligonoconvesso.h"

const unsigned int Quadrilatero::numLati = 4;

Quadrilatero::Quadrilatero(QString s, const vector<Vertice> &v) : PoligonoConvesso(s, v, 4){}

Quadrilatero* Quadrilatero::clone() const
{
    return new Quadrilatero(*this);
}

double Quadrilatero::getPerimetro() const
{
    double per=0;
    for(unsigned int i=0; i<Vertici.size(); ++i)
    {
        if(i+1 == Vertici.size())
            per += distanza(Vertici[i], Vertici[0]);
        else
            per += distanza(Vertici[i], Vertici[i+1]);
    }
    return per;
}

double Quadrilatero::getArea() const
{ // formula di Brahmagupta
    double p = getPerimetro()/2;

    double a = distanza(Vertici[0], Vertici[1]);
    double b = distanza(Vertici[1], Vertici[2]);
    double c = distanza(Vertici[2], Vertici[3]);
    double d = distanza(Vertici[3], Vertici[0]);

    return sqrt((p-a)*(p-b)*(p-c)*(p-d));
}

double Quadrilatero::getSommaAngoli() const
{
    return 360;
}

unsigned int Quadrilatero::getNumLati() const
{
    return numLati;
}

double Quadrilatero::getDiagolale(unsigned int v1) const
{
    if(v1<Vertici.size())
    {
        if(v1==Vertici.size()-1)
            return distanza(Vertici[v1], Vertici[1]);
        else if(v1==Vertici.size()-2)
            return distanza(Vertici[v1], Vertici[0]);
        else
            return distanza(Vertici[v1], Vertici[v1+2]);
    }
    else
        throw std::invalid_argument("Posizioni non valide!");
}

bool Quadrilatero::operator<(const Figura &f) const
{
    return getArea() < f.getArea();
}

bool Quadrilatero::operator>(const Figura &f) const
{
    return getArea() > f.getArea();
}

string Quadrilatero::toString() const
{
    stringstream buffer;
    buffer << *this;
    return buffer.str();
}

ostream &operator<<(ostream &os, const Quadrilatero &q)
{
    q.print(os);
    return os;
}
