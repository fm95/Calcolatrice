#include "figura.h"

int Figura::maxNomeLength=14; //francescominna

Figura::Figura(QString s)
{
    if(s.size() <= maxNomeLength)
        Nome=s;
    else
        throw std::invalid_argument("Nome troppo lungo!");
}

QString Figura::getNome() const
{
    return Nome;
}

void Figura::setNome(QString s)
{
    if(s.size() <= maxNomeLength)
        Nome=s;
    else
        throw std::invalid_argument("Nome troppo lungo!");
}
