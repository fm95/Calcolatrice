#ifndef FIGURA_H
#define FIGURA_H

#include <ostream>
#include <QString>

using std::ostream;

class Figura
{
public:
    Figura(QString s);
    virtual ~Figura() throw() =default;

    virtual double getPerimetro() const =0;
    virtual double getArea() const =0;

    virtual bool operator<(const Figura&) const =0;
    virtual bool operator>(const Figura&) const =0;

    QString getNome() const;
    void setNome(QString);

private:
    QString Nome;
    static int maxNomeLength;

    virtual void print(ostream &) const =0;
};

#endif // FIGURA_H
