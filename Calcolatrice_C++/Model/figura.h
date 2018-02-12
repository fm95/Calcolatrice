#ifndef FIGURA_H
#define FIGURA_H

#include <ostream>
#include <QString>
#include <string>
#include <sstream>

using std::string;
using std::ostream;
using std::stringstream;

class Figura
{
public:
    Figura(QString ="");
    virtual ~Figura() throw() = default; // provare a togliere throw()

    virtual double getPerimetro() const =0;
    virtual double getArea() const =0;

    virtual bool operator<(const Figura&) const =0;
    virtual bool operator>(const Figura&) const =0;
    virtual string toString() const =0;

    QString getNome() const;
    void setNome(QString);

protected:
    QString Nome;
    virtual void print(ostream &) const =0;

private:
    static int maxNomeLength;

};

#endif // FIGURA_H
