#include "poligonoconvesso.h"
#include "triangolo.h"
#include "quadrato.h"

unsigned int PoligonoConvesso::limiteVertici = 20;

PoligonoConvesso::PoligonoConvesso(QString s, vector<Vertice> &v, const unsigned int nLati):Figura(s)
{
    if(!v.empty() && v.size()==nLati && nLati<=limiteVertici)
    {
        double sum = 0;
        for(unsigned int i=0; i<v.size(); ++i)
        {
            if(i==0)
                v[0].Vertice::setGradi(AngoloVertici(v[v.size()-1], v[0], v[1]));
            else if((i+1) != v.size())
                v[i].Vertice::setGradi(AngoloVertici(v[i-1], v[i], v[i+1]));
            else if((i+1) == v.size())
                v[i].Vertice::setGradi(AngoloVertici(v[i-1], v[i], v[0]));

            sum += v[i].Vertice::getGradiAngolo();
        }
        if(controllaVertici(v) && sum>=(180*(nLati-2)-0.000001)
                && sum<=(180*(nLati-2)+0.000001))
            Vertici = v;
    }
}

double PoligonoConvesso::getLato(double i1, double pos) const
{
    if(pos!=-1 && pos>=0 && pos<Vertici.size())
    {
        if(pos==(Vertici.size()-1) && Vertici[pos].Vertice::getInfo()==i1)
            return distanza(Vertici[pos], Vertici[0]);
        else if(Vertici[pos].Vertice::getInfo()==i1)
            return distanza(Vertici[pos], Vertici[pos+1]);
    }
    else
    { // info diversi, prendo i primi due che soddisfano l'uguaglianza
        for(unsigned int i=0; i<Vertici.size(); ++i)
        {
            if(i==(Vertici.size()-1) && // ultimo vertice
                    Vertici[i].Vertice::getInfo()==i1)
                return distanza(Vertici[i], Vertici[0]);

            else if(Vertici[i].Vertice::getInfo()==i1) // vertice qualsiasi
                return distanza(Vertici[i], Vertici[i+1]);
        }
    }
    return -1;
}

double PoligonoConvesso::getAngolo(double i1, double pos) const
{
    if(pos!=-1 && pos>=0 && pos<Vertici.size()
            && Vertici[pos].Vertice::getInfo()==i1)
        return Vertici[pos].Vertice::getGradiAngolo();
    else
    {
        for(unsigned int i=0; i<Vertici.size(); ++i)
        {
            if(Vertici[i].Vertice::getInfo()==i1)
                return Vertici[i].Vertice::getGradiAngolo();
        }
    }
    return -1;
}

bool PoligonoConvesso::controllaVertici(const vector<Vertice> &v){
    // vertici tutti diversi e angoli >0 & <180
    for(unsigned int i=0; i<v.size(); ++i)
    {
        if(v[i].getGradiAngolo()<=0 || v[i].getGradiAngolo()>=180)
            return false;
        for(unsigned int j=i+1; j<v.size(); ++j)
        {
                if(v[i] == v[j])
                    return false;
        }
    }
    return true;
}

PoligonoConvesso* PoligonoConvesso::costruisci(QString s, vector<Vertice> &v)
{
    if(v.size()==3)
        return new Triangolo(s, v);
    else if(v.size()==4)
    {
        Quadrilatero* q = new Quadrilatero(s, v);
        if(!q->isEquiangolo())
           return q;
        else if(!q->isEquilatero() && q->isEquiangolo())
            return new Rettangolo(s, v);
        else if(q->isEquilatero() && q->isEquiangolo())
            return new Quadrato(s, v);
    }
//    else if(v.size() == 5)... // Pentagono
    return nullptr;
}

int PoligonoConvesso::WindingNumberInclusion(const Vertice &P, const vector<Vertice> &V)
{ // Winding Number Algorithm
    int wn = 0;
    for (unsigned int i=0; i<V.size(); i++)
    {
        if (V[i].getY() <= P.getY())
        {
            if (V[i + 1].getY()  > P.getY())
            {
                int l = isLeft(V[i], V[i + 1], P);
                if (l > 0)
                    ++wn;
                else if (l == 0)
                    return 0;
            }
        }
       else
        {
            if (V[i + 1].getY() <= P.getY())
            {
                int l = isLeft(V[i], V[i + 1], P);
                if (l < 0)
                    --wn;
                else if (l == 0)
                    return 0;
            }
        }
    }
    return wn;
}

int PoligonoConvesso::isLeft(const Vertice &v0, const Vertice &v1, const Vertice &v2)
{
    return ( (v1.getX() - v0.getX()) * (v2.getY() - v0.getY())
             - (v2.getX() -  v0.getX()) * (v1.getY() - v0.getY()) );;
}

int PoligonoConvesso::getNumDiagonali() const
{
    return getNumLati() * ( getNumLati() - 3 ) / 2;
}

bool PoligonoConvesso::isEquiangolo() const
{
    for(unsigned int i=1; i<Vertici.size(); ++i)
    {
        if(Vertici[0].getGradiAngolo() != Vertici[i].getGradiAngolo())
            return false;
    }
    return true;
}

bool PoligonoConvesso::isEquilatero()const
{
    int dist = distanza(Vertici[0], Vertici[1]);
    for(unsigned int i=2; i<Vertici.size(); ++i)
    {
        if(dist != distanza(Vertici[i-1], Vertici[i]))
            return false;
    }
    return PoligonoConvesso::isEquiangolo();
}

bool PoligonoConvesso::isRegolare()const
{
    return PoligonoConvesso::isEquilatero() && PoligonoConvesso::isEquiangolo();
}

void PoligonoConvesso::modificaInfo(unsigned int pos, double info)
{
    if(pos < Vertici.size())
        Vertici[pos].setInfo(info);
}

bool PoligonoConvesso::infoUguali() const
{
    for(unsigned int i=1; i<Vertici.size(); ++i)
    {
        if(Vertici[i-1].Vertice::getInfo() != Vertici[i].Vertice::getInfo())
            return false;
    }
    return true;
}

PoligonoConvesso* PoligonoConvesso::inserisciVertice(QString s, Vertice &v)
{ // per ora si puo' creare al massimo un quadrilatero, altrimenti va estesa la gerarchia
    if(Vertici.size()<4)
    {
        if( WindingNumberInclusion(v, Vertici)==0 )
        {
            Vertici.push_back(v);
            return costruisci(s, Vertici);
        }
        else
            return nullptr;
    }
    return nullptr;
}

PoligonoConvesso* PoligonoConvesso::eliminaVertice(QString s, unsigned int pos)
{ // si puo' eliminare solo da un poligono con almeno 4 vertici
    if(Vertici.size()>3 && pos<Vertici.size())
    {
        int i=pos;
        for(auto it=Vertici.begin(); i>=0; ++it, --i)
        {
            if(i==0)
                it=Vertici.erase(it);
        }
        return costruisci(s, Vertici);
    }
    else
        return nullptr;
}

double PoligonoConvesso::Max() const
{
    double m = Vertici[0].getInfo();
    for(unsigned int i=1; i<Vertici.size(); ++i)
    {
        if(Vertici[i].getInfo() > m)
            m = Vertici[i].getInfo();
    }
    return m;
}

double PoligonoConvesso::Min() const
{
    double m = Vertici[0].getInfo();
    for(unsigned int i=1; i<Vertici.size(); ++i)
    {
        if(Vertici[i].getInfo() < m)
            m = Vertici[i].getInfo();
    }
    return m;
}

double PoligonoConvesso::AVG() const
{
    double m = Vertici[0].getInfo();
    for(unsigned int i=1; i<Vertici.size(); ++i)
        m += Vertici[i].getInfo();
    return m/Vertici.size();
}

double PoligonoConvesso::Somma() const
{
    double m = Vertici[0].getInfo();
    for(unsigned int i=1; i<Vertici.size(); ++i)
        m += Vertici[i].getInfo();
    return m;
}

double PoligonoConvesso::Sottrazione() const
{
    double m = Vertici[0].getInfo();
    for(unsigned int i=1; i<Vertici.size(); ++i)
        m -= Vertici[i].getInfo();
    return m;
}

bool PoligonoConvesso::operator==(const PoligonoConvesso &p) const
{
    return (Vertici.size()==p.Vertici.size() && Vertici==p.Vertici);
}

bool PoligonoConvesso::operator!=(const PoligonoConvesso &p) const
{
    return !PoligonoConvesso::operator==(p);
}

PoligonoConvesso& operator+(PoligonoConvesso &p1, const PoligonoConvesso &p2)
{
    if(typeid(p1)==typeid(p2))
    {
        for(unsigned int i=0; i<p1.Vertici.size(); ++i)
            p1.Vertici[i].Vertice::setInfo(p1.Vertici[i].Vertice::getInfo() + p2.Vertici[i].Vertice::getInfo());
    }
    return p1;
}

PoligonoConvesso& operator-(PoligonoConvesso &p1, const PoligonoConvesso &p2)
{
    if(typeid(p1)==typeid(p2))
    {
        for(unsigned int i=0; i<p1.Vertici.size(); ++i)
            p1.Vertici[i].Vertice::setInfo(p1.Vertici[i].Vertice::getInfo() - p2.Vertici[i].Vertice::getInfo());
    }
    return p1;
}
