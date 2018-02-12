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
        PoligonoConvesso *aux = (*it)->inserisciVertice(nome, v);
        list.push_front(aux);
    }
}

void Dati::deleteVertice(QString nome, unsigned int pos)
{
    if(!list.empty())
    {
        auto it=list.begin();
        while((*it)->getNome()!=nome && it!=list.end())
        { ++it; }
        PoligonoConvesso *aux = (*it)->eliminaVertice(nome, pos);
        list.push_front(aux);
    }
}

double Dati::getSomma(QString nome) const
{
    auto it=list.cbegin();
    while((*it)->getNome()!=nome && it!=list.cend())
    {++it;}
    return (*it)->Somma();
}

double Dati::getSottrazione(QString nome) const
{
    auto it=list.cbegin();
    while((*it)->getNome()!=nome && it!=list.cend())
    {++it;}
    return (*it)->Sottrazione();
}

bool Dati::nomeUnico(QString nome) const
{
    for(auto it=list.cbegin(); it!=list.cend(); ++it)
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
