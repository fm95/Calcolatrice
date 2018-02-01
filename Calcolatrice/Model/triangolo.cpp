#include "triangolo.h"

const unsigned int Triangolo::numLati = 3;

Triangolo::Triangolo(QString s, vector<Vertice> v): PoligonoConvesso(s, v, 3) {}

Triangolo *Triangolo::clone() const
{
    return new Triangolo(*this);
}

double Triangolo::getPerimetro() const
{
    double c1 = distanza(Vertici[0], Vertici[1]);
    double c2 = distanza(Vertici[1], Vertici[2]);
    double c3 = distanza(Vertici[2], Vertici[0]);

    return c1 + c2 + c3;
}

double Triangolo::getArea() const
{ // triangolo generico
    double x0=Vertici[0].getX(), y0=Vertici[0].getY();
    double x1=Vertici[1].getX(), y1=Vertici[1].getY();
    double x2=Vertici[2].getX(), y2=Vertici[2].getY();

    return abs(x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1)) / 2;
}

double Triangolo::getSommaAngoli() const
{
    if(Vertici.size()==3)
    {
        double sum = 0;
        for(unsigned int i=0; i<Vertici.size(); ++i)
            sum += Vertici[i].Vertice::getGradiAngolo();
        if( sum>=180-0.00000001 && sum<=180+0.00000001 )
            return 180;
    }
    return -1;
}

unsigned int Triangolo::getNumLati() const
{
    return numLati;
}

double Triangolo::getApotema() const
{ // raggio della circonferenza inscritta nel triangolo
    if(isRegolare())
        return 0.289*getLato(Vertici[0].getInfo());
    return -1;
}

bool Triangolo::isIsoscele()const
{ // 2 lati uguali
    double c1 = distanza(Vertici[0], Vertici[1]);
    double c2 = distanza(Vertici[1], Vertici[2]);
    double c3 = distanza(Vertici[2], Vertici[0]);
    if(c1==c2 || c1==c3 || c2==c3)
        return true;
    else
        return false;
}

bool Triangolo::isScaleno()const
{ // tutti lati & angoli diversi
    return !isIsoscele() && !PoligonoConvesso::isEquilatero();
}

bool Triangolo::isRettangolo()const
{ // un angolo di 90 gradi
    if(PoligonoConvesso::Vertici[0].getGradiAngolo()==90
       || PoligonoConvesso::Vertici[1].getGradiAngolo()==90
       || PoligonoConvesso::Vertici[2].getGradiAngolo()==90)
        return true;
    else
        return false;
}

bool Triangolo::isOttusangolo()const
{ // un angolo > 90 gradi
    if(PoligonoConvesso::Vertici[0].getGradiAngolo()>90
       || PoligonoConvesso::Vertici[1].getGradiAngolo()>90
       || PoligonoConvesso::Vertici[2].getGradiAngolo()>90)
        return true;
    else
        return false;
}

bool Triangolo::isAcutangolo()const
{ // tutti gli angoli < 90 gradi
    if(PoligonoConvesso::Vertici[0].getGradiAngolo()<90
       && PoligonoConvesso::Vertici[1].getGradiAngolo()<90
       && PoligonoConvesso::Vertici[2].getGradiAngolo()<90)
        return true;
    else
        return false;
}

bool Triangolo::operator<(const Figura &f) const
{
    return getArea() < f.getArea();
}

bool Triangolo::operator>(const Figura &f) const
{
    return getArea() > f.getArea();
}

void Triangolo::print(std::ostream &stream) const
{
    stream<<getNome().toStdString()<<": ";
    for(int i=0; i<3; ++i)
    {
        stream<<"{("<<Vertici[i].Punto::getX()<<","<<Vertici[i].Punto::getY()<<") ";
        stream<<Vertici[i].getInfo();
        stream<<" ["<<Vertici[i].getGradiAngolo()<<"°]}";

        i!=2? stream<<" -> " : stream<<"";
    }
}

ostream& operator<<(ostream &stream, const Triangolo &t)
{
    t.print(stream);
    return stream;
}
