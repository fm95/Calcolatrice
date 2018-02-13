#include "dati.h"

Dati::~Dati()
{
    eliminaTutto(); // elimino tutta la lista
}

void Dati::costruisci(QString s, const vector<Vertice> &v)
{
    if(v.size()==3)
        list.push_front(new Triangolo(s, v));
    else if(v.size()==4)
    {
        Quadrilatero* q = new Quadrilatero(s, v);
        if(!q->isEquiangolo()) // quadrialatero
            list.push_front(q);
        else if(!q->isEquilatero() && q->isEquiangolo()) // rettangolo
        {
            list.push_front(new Rettangolo(s, v));
            delete q;
        }
        else if(q->isEquilatero() && q->isEquiangolo()) // quadrato
        {
            list.push_front(new Quadrato(s, v));
            delete q;
        }
    }
}
/* I nuovi poligoni vengono inseriti all'inizio della list (push_front) perche' molto probabilmente
 * le operazioni dell'utente si svolgeranno proprio sull'ultimo inserito; inserendo all'inizio, e
 * cercando un poligono attraverso il suo nome, la ricerca avra' subito successo, senza scorrere
 * tutta la lista.
*/

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
    auto it=list.begin();
    while((*it)->getNome()!=nome && it!=list.end())
    { ++it; }
    list.push_front((*it)->inserisciVertice(nome, v));
}

void Dati::eliminaVertice(QString vecchio, QString nuovo, unsigned int pos)
{
    for(auto it=list.begin(); it!=list.end(); ++it)
    {
        if( (*it)->getNome() == vecchio )
        {
            list.push_front((*it)->eliminaVertice(nuovo, pos));
            return;
        }
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

double Dati::getDiagonale(QString nome, unsigned int pos) const
{
    for(auto it=list.constBegin(); it!=list.constEnd(); ++it)
    {
        if((*it)->getNome() == nome)
        {
            return dynamic_cast<Quadrilatero*>(*it)->getDiagolale(pos);
        }
    }
    return -1;
}

double Dati::getApotema(QString nome) const
{
    for(auto it=list.constBegin(); it!=list.constEnd(); ++it)
    {
        if((*it)->getNome()==nome)
        { // se il poligono e' regolare viene controllato nel controller
            if((*it)->getNumLati()==3)
                return (static_cast<Triangolo*>(*it))->getApotema();
            else if((*it)->getNumLati()==4)
                return (static_cast<Quadrato*>(*it))->getApotema();
        }
    }
    return -1;
}

bool Dati::isRegolare(QString nome) const
{
    for(auto it=list.constBegin(); it!=list.constEnd(); ++it)
    {
        if((*it)->getNome() == nome)
            return (*it)->isRegolare();
    }
    return true;
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
    for(auto it=list.begin(); it!=list.end(); ++it)
    {
        if((*it)->getNome() == nome)
            return (*it);
    }
}
