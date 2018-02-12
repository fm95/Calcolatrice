#include "poligonoconvesso.h"
#include "triangolo.h"
#include "quadrato.h"

unsigned int PoligonoConvesso::limiteVertici = 20;

PoligonoConvesso::PoligonoConvesso(QString s, const vector<Vertice> &v, const unsigned int nLati) :
    Figura(s)
{
    if(!v.empty() && v.size()==nLati && nLati<=limiteVertici)
    {
        bool test=true;
        double sum = 0;
        for(unsigned int i=0; test && i<v.size(); ++i)
        {
            if(test)
            { // angoli >0 e <180
                double aux = calcolaAngolo(v,i);
                if(aux>0 && aux<180)
                // gradi angoli corretti
                    sum += aux;
                else
                    test=false;
            }
        }
        if(test && sum>=(180*(nLati-2)-0.000001) && sum<=(180*(nLati-2)+0.000001))
            Vertici = v;
        else
            throw invalid_argument("I vertici non formano un poligono convesso!");
    }
    else
        throw invalid_argument("Inserisci un numero valido di vertici, massimo 4!");
}

double PoligonoConvesso::calcolaAngolo(const vector<Vertice> &p, unsigned int pos)
{
    if(pos==0)
        return AngoloVertici(p[p.size()-1], p[0], p[1]);
    else if((pos+1) != p.size())
        return AngoloVertici(p[pos-1], p[pos], p[pos+1]);
    else if((pos+1) == p.size())
        return AngoloVertici(p[pos-1], p[pos], p[0]);
    else
        return -1;
}

void PoligonoConvesso::print(std::ostream &stream) const
{
    stream<<Nome.toStdString()<<": ";
    for(unsigned int i=0; i<Vertici.size(); ++i)
    {
        stream<<"("<<Vertici[i].getX()<<","<<Vertici[i].getY()<<") ";
        stream<<Vertici[i].getInfo()<<" ";
        stream<<"[";
        stream<<calcolaAngolo(Vertici, i);
        stream<<"\u00B0]";

        i!=(Vertici.size()-1)? stream<<" > " : stream<<"";
    }
}

vector<Vertice> &PoligonoConvesso::getVertici()
{
    return Vertici;
}

double PoligonoConvesso::getLato(double i1, double pos) const
{
    if(pos>=0 && pos<Vertici.size())
    {
        if(pos==(Vertici.size()-1) && Vertici[pos].getInfo()==i1)
            return distanza(Vertici[pos], Vertici[0]);
        else if(Vertici[pos].getInfo()==i1)
            return distanza(Vertici[pos], Vertici[pos+1]);
    }
    else
    { // info diversi, prendo i primi due che soddisfano l'uguaglianza
        for(unsigned int i=0; i<Vertici.size(); ++i)
        {
            if(i==(Vertici.size()-1) && // ultimo vertice
                    Vertici[i].getInfo()==i1)
                return distanza(Vertici[i], Vertici[0]);

            else if(Vertici[i].getInfo()==i1) // vertice qualsiasi
                return distanza(Vertici[i], Vertici[i+1]);
        }
    }
    throw std::invalid_argument("Info o posizione non valida!");
}

double PoligonoConvesso::getAngolo(double i1, double pos) const
{
    if(pos>=0 && pos<Vertici.size() // se passo la posizione
            && Vertici[pos].getInfo()==i1)
        return calcolaAngolo(Vertici,pos);
    else
    {
        for(unsigned int i=0; i<Vertici.size(); ++i)
        {
            if(Vertici[i].getInfo()==i1)
                return calcolaAngolo(Vertici,i);
        }
    }
    throw std::invalid_argument("Info o posizione non valida");
}

int WindingNumberInclusion(const Vertice &P, const vector<Vertice>& V)
{ // Winding Number Algorithm
    int wn = 0;
    for (unsigned int i=0; i<V.size(); i++)
    {
        if (V[i].getY() <= P.getY())
        {
            if (V[i + 1].getY()  > P.getY())
            {
                double l = isLeft(V[i], V[i + 1], P);
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
                double l = isLeft(V[i], V[i + 1], P);
                if (l < 0)
                    --wn;
                else if (l == 0)
                    return 0;
            }
        }
    }
    return wn;
}
double isLeft(const Vertice &v0, const Vertice &v1, const Vertice &v2)
{
    return ( (v1.getX() - v0.getX()) * (v2.getY() - v0.getY())
             - (v2.getX() -  v0.getX()) * (v1.getY() - v0.getY()) );
}

int PoligonoConvesso::getNumDiagonali() const
{
    return getNumLati() * ( getNumLati() - 3 ) / 2;
}

bool PoligonoConvesso::isEquiangolo() const
{
    for(unsigned int i=1; i<Vertici.size(); ++i)
    {
        if(calcolaAngolo(Vertici,0) != calcolaAngolo(Vertici,i))
            return false;
    }
    return true;
}

bool PoligonoConvesso::isEquilatero()const
{
    double dist = distanza(Vertici[0], Vertici[1]);
    for(unsigned int i=2; i<Vertici.size(); ++i)
    {
        if(dist != distanza(Vertici[i-1], Vertici[i]))
            return false;
    }
    return isEquiangolo();
}

bool PoligonoConvesso::isRegolare()const
{
    return isEquilatero() && isEquiangolo();
}

void PoligonoConvesso::modificaInfo(unsigned int pos, double info)
{
    if(pos < Vertici.size())
        Vertici[pos].setInfo(info);
    else
        throw std::invalid_argument("Posizione non valida!");
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

PoligonoConvesso* PoligonoConvesso::costruisci(QString s, const vector<Vertice> &v)
{ // vector v gia' controllato !!
    if(v.size()==3)
        return new Triangolo(s,v);
    else if(v.size()==4)
    {
        Quadrilatero* q = new Quadrilatero(s, v);
        if(!q->isEquiangolo())
           return q;
        else if(!q->isEquilatero() && q->isEquiangolo())
        {
            delete q;
            return new Rettangolo(s, v);
        }
        else if(q->isEquilatero() && q->isEquiangolo())
        {
            delete q;
            return new Quadrato(s, v);
        }
    }
    return nullptr;
}

PoligonoConvesso* PoligonoConvesso::inserisciVertice(QString nome, Vertice& v)
{ // per ora si puo' creare al massimo un quadrilatero, altrimenti va estesa la gerarchia
    if(Vertici.size()<4)
    {
        if( WindingNumberInclusion(v, Vertici) == 0 )
        {
            vector<Vertice> aux = Vertici;
            aux.push_back(v);
            PoligonoConvesso *p = costruisci(nome, aux);
            aux.clear();
            return p;
        }
        else
            throw std::invalid_argument("Il nuovo poligono non e' convesso!");
    }
    return nullptr;
}

PoligonoConvesso* PoligonoConvesso::eliminaVertice(QString nome, unsigned int pos)
{ // si puo' eliminare solo da un poligono con almeno 4 vertici
    if(Vertici.size()>3)
    {
        if(pos < Vertici.size())
        {
            vector<Vertice> aux = Vertici;
            bool b=false;
            for(auto it=aux.begin(); !b && it!= aux.end(); ++it, --pos)
            {
                if(pos==0)
                {
                    it=aux.erase(it);
                    b=true;
                }
            }
            PoligonoConvesso* p = costruisci(nome, aux);
            aux.clear();
            return p;
        }
        else
            throw std::invalid_argument("Posizione non valida!");
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
    double m=0;
    for(unsigned int i=0; i<Vertici.size(); ++i)
        m += Vertici[i].getInfo();
    return m/Vertici.size();
}

double PoligonoConvesso::Somma() const
{
    double m=0;
    for(unsigned int i=0; i<Vertici.size(); ++i)
        m += Vertici[i].getInfo();
    return m;
}

double PoligonoConvesso::Sottrazione() const
{
    double m=0;
    for(unsigned int i=0; i<Vertici.size(); ++i)
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
