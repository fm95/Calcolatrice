#include "dati.h"

Dati::~Dati()
{
    eliminaTutto();
}

void Dati::costruisci(QString s, const vector<Vertice> &v)
{
    if(v.size()==3)
        list.push_front(new Triangolo(s, v));
    else if(v.size()==4)
    {
        Quadrilatero* q = new Quadrilatero(s, v);
        if(!q->isEquiangolo())
            list.push_front(q);
        else if(!q->isEquilatero() && q->isEquiangolo())
        {
            list.push_front(new Rettangolo(s, v));
            delete q;
        }
        else if(q->isEquilatero() && q->isEquiangolo())
        {
            list.push_front(new Quadrato(s, v));
            delete q;
        }
    }
}

void Dati::eliminaFigura(QString nome)
{
    for(auto it=list.begin(); !list.isEmpty() && it!=list.end(); ++it)
    {
        if((*it)->getNome() == nome)
        {
            delete *it;
            it = list.erase(it);
            return;
        }
    }
}

void Dati::eliminaTutto()
{
    for(auto it=list.begin(); !list.isEmpty() && it!=list.end();)
    {
        delete (*it);
        it = list.erase(it);
    }
    list.clear();
}

void Dati::modInfo(QString nome, unsigned int pos, double info)
{
    for(auto it=list.begin(); it!=list.end(); ++it)
    {
        if((*it)->getNome() == nome)
            (*it)->modificaInfo(pos, info);
    }
}

void Dati::insertVertice(QString nome, Vertice &v)
{
    if(!list.empty())
    {
        auto it=list.begin();
        while((*it)->getNome()!=nome && it!=list.end())
        { ++it; }
//        PoligonoConvesso *aux = (*it)->inserisciVertice(nome, v);
//        list.push_front(aux);

        list.push_front((*it)->inserisciVertice(nome, v));
    }
}

void Dati::deleteVertice(QString nome, unsigned int pos)
{
    if(!list.empty())
    {
        auto it=list.begin();
        while((*it)->getNome()!=nome && it!=list.end())
        { ++it; }
//        PoligonoConvesso *aux = (*it)->eliminaVertice(nome, pos);
//        list.push_front(aux);

        list.push_front((*it)->eliminaVertice(nome, pos));
    }
}

double Dati::getMax(QString nome) const
{
    auto it=list.constBegin();
    while(it!=list.constEnd() && (*it)->getNome()!=nome)
    {++it;}
    return (*it)->Max();
}

double Dati::getMin(QString nome) const
{
    auto it=list.constBegin();
    while(it!=list.constEnd() && (*it)->getNome()!=nome)
    {++it;}
    return (*it)->Min();
}

double Dati::getAVG(QString nome) const
{
    auto it=list.constBegin();
    while(it!=list.constEnd() && (*it)->getNome()!=nome)
    {++it;}
    return (*it)->AVG();
}

double Dati::getSomma(QString nome) const
{
    auto it=list.constBegin();
    while(it!=list.constEnd() && (*it)->getNome()!=nome)
    {++it;}
    return (*it)->Somma();
}

double Dati::getSottrazione(QString nome) const
{
    auto it=list.constBegin();
    while(it!=list.constEnd() && (*it)->getNome()!=nome)
    {++it;}
    return (*it)->Sottrazione();
}

double Dati::getApotema(QString nome) const
{
    for(auto it=list.constBegin(); it!=list.constEnd(); ++it)
    {
        if((*it)->getNome()!=nome)
        {
            Triangolo *t = dynamic_cast<Triangolo*>(*it);
            if(t) // se e' regolare viene controllato nel controller
                return t->getApotema();
            else
            {
                Quadrato *q = dynamic_cast<Quadrato*>(*it);
                if(q)
                    return q->getApotema();
            }
        }
    }
}

bool Dati::nomeUnico(QString nome) const
{
    for(auto it=list.constBegin(); it!=list.constEnd(); ++it)
    {
        if((*it)->getNome() == nome)
            return false;
    }
    return true;
}

PoligonoConvesso* &Dati::getPoligono(QString nome)
{
    bool trovato=false;
    for(auto it=list.begin(); !trovato && it!=list.end(); ++it)
    {
        if((*it)->getNome() == nome)
            return (*it);
    }
}
