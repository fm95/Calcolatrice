#include "figura.h"

int Figura::maxNomeLength=14; //francescominna

Figura::Figura(QString s)
{
    if(s.size() <= maxNomeLength)
        Nome=s;
}

QString Figura::getNome() const
{
    return Nome;
}

void Figura::setNome(QString s)
{
    Nome=s;
}
