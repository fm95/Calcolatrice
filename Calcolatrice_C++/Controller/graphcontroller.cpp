#include "graphcontroller.h"
#include "View/poligonic.h"


GraphController::GraphController(Calcolatrice *c) :
    dati(new Dati()),
    calc(c),
    ins(0)
{}

GraphController::~GraphController()
{
    delete dati;
}

void GraphController::c_inserisciFigura()
{
    calc->setDisabled(true);
    ins = new insertFigura(this);
}

void GraphController::c_eliminaV(QString vecchio, QString nuovo, unsigned int pos)
{
    try
    {
        dati->eliminaVertice(vecchio, nuovo, pos);
        PoligonoConvesso *& newP =  dati->getPoligono(nuovo); // alias di puntatore
        vector<Vertice> &v = newP->getVertici(); // alias

        QPolygonF f; // poligono da disegnare
        for(unsigned int i=0; i<v.size(); ++i)
            f << QPointF(v[i].Punto::getX(), v[i].Punto::getY());

        c_costruisciQp(*newP, nuovo, f); // costruisce il QPolygonF da stampare
    }
    catch(const std::invalid_argument &i)
    {
        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Impossibile creare la nuova figura");
        warning.setText("I vertici non formano un poligono convesso!");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();

//        calc->errorPrint(QString::fromStdString(i.what()));
    }
}

// Inserisce nuova figura
void GraphController::c_addFigura(QString n, const vector<Vertice> &v)
{
    try
    {
        dati->costruisci(n, v);
        PoligonoConvesso *&newP =  dati->getPoligono(n);

        QPolygonF f; // poligono da disegnare
        for(unsigned int i=0; i<v.size(); ++i)
            f << QPointF(v[i].Punto::getX(), v[i].Punto::getY());

        c_costruisciQp(*newP, n, f); // costruisce il QPolygonF da stampare
    }
    catch(const std::invalid_argument &i)
    {
        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Impossibile inserire la nuova figura");
        warning.setText("I vertici inseriti non formano un poligono convesso!");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();

//        calc->errorPrint(QString::fromStdString(i.what()));
    }
}

// Elimina una figura
bool GraphController::c_eliminaFigura(QString nome)
{
    QMessageBox warning;
    warning.setIcon(QMessageBox::Critical);
    warning.setWindowTitle("Elimina Figura");
    warning.setText("Sei sicuro di eliminare la figura selezionata?");
    warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    warning.setDefaultButton(QMessageBox::No);
    c_enabledQd(false);
    int i = warning.exec();
    if(i == QMessageBox::Yes)
    {
        dati->eliminaFigura(nome);
        c_enabledQd(true);
        return true;
    }
    else
    {
        c_enabledQd(true);
        return false;
    }
}

// Rimuovi tutte le figure
bool GraphController::c_eliminaTutto()
{
    QMessageBox warning;
    warning.setIcon(QMessageBox::Critical);
    warning.setWindowTitle("Elimina tutto");
    warning.setText("Sei sicuro di eliminare tutte le figure?");
    warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    warning.setDefaultButton(QMessageBox::No);
    c_enabledQd(false);
    int i = warning.exec();
    if(i == QMessageBox::Yes)
    {
        dati->eliminaTutto();
        c_enabledQd(true);
        return true;
    }
    else
    {
        c_enabledQd(true);
        return false;
    }
}

// Inserisce un nuovo vertice in una nuova figura
void GraphController::c_inserisciVertice(QString nome)
{
    calc->setDisabled(true);
    ins = new insertFigura(nome, this);
}

// Elimina un vertice
void GraphController::c_eliminaVertice(QString nome)
{
    calc->setDisabled(true);
    ins = new insertFigura(1, nome, this);
}

// Modifica l'info di un vertice di una figura
void GraphController::c_modificaInfo(QString nome)
{
    calc->setDisabled(true);
    ins = new insertFigura(nome, -1, this); // il -1 e' solo per riconoscere il costruttore
}

void GraphController::c_aggiornaInfo(QString nome, unsigned int pos, double info)
{
    dati->modInfo(nome, pos, info);
    c_stampaFigura(nome);
}

void GraphController::c_Diagonale(QString nome)
{
    calc->setDisabled(true);
    ins = new insertFigura(nome, 5, 5, this);
}

void GraphController::c_getDiagonale(QString nome, unsigned int pos) const
{
    calc->infoPrint(QString("Diagonale = " + QString::number(dati->getDiagonale(nome, pos))));
}

double GraphController::c_getMax(QString nome) const
{
    return dati->getMax(nome);
}

double GraphController::c_getMin(QString nome) const
{
    return dati->getMin(nome);
}

QString GraphController::c_getAVG(QString nome) const
{
    QString s = "(";
    PoligonoConvesso *& newP =  dati->getPoligono(nome); // alias di puntatore
    vector<Vertice> &v = newP->getVertici();
    for(unsigned int i=0; i<v.size(); ++i)
    {
        double inf = v[i].getInfo();
        inf < 0 ? s += "(" + QString::number(inf) + ")" : s += QString::number(inf);
        i < v.size()-1 ? s += " + " : s += ")/" + QString::number(v.size()) + " = ";
    }
    s += QString::number(dati->getAVG(nome));
    return s;
}

QString GraphController::c_getSomma(QString nome) const
{
    QString s = "";
    PoligonoConvesso *& newP =  dati->getPoligono(nome); // alias di puntatore
    vector<Vertice> &v = newP->getVertici();
    for(unsigned int i=0; i<v.size(); ++i)
    {
        double inf = v[i].getInfo();
        inf < 0 ? s += "(" + QString::number(inf) + ")" : s += QString::number(inf);
        i < v.size()-1 ? s += " + " : s += " = ";
    }
    s += QString::number(dati->getSomma(nome));
    return s;
}

QString GraphController::c_getSottrazione(QString nome) const
{
    QString s = "";
    PoligonoConvesso *& newP =  dati->getPoligono(nome); // alias di puntatore
    vector<Vertice> &v = newP->getVertici();
    for(unsigned int i=0; i<v.size(); ++i)
    {
        double inf = v[i].getInfo();
        inf < 0 ? s += "(" + QString::number(inf) + ")" : s += QString::number(inf);
        i < v.size()-1 ? s += " - " : s += " = ";
    }
    s += QString::number(dati->getSottrazione(nome));
    return s;
}

double GraphController::c_getApotema(QString nome) const
{
    if(dati->getPoligono(nome)->isRegolare())
        return dati->getApotema(nome);
    else
    {
        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Impossibile calcolare apotema");
        warning.setText("Non si puo' calcolare l'apotema di un poligono non regolare!");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
        return -1;
    }
}

bool GraphController::c_isRegolare(QString nome) const
{
    return dati->isRegolare(nome);
}

void GraphController::c_stampaFigura(QString n)
{
    calc->infoPrint(QString::fromStdString(dati->getPoligono(n)->toString()));
}

void GraphController::c_enabledQd(bool b)
{
    if(calc)
        calc->setEnabled(b);
}

PoligonoConvesso*& GraphController::c_getPoligono(QString n) const
{
    return dati->getPoligono(n);
}

vector<Vertice>& GraphController::c_getVertici(QString nome)
{
    return dati->getPoligono(nome)->getVertici();
}

bool GraphController::c_getUnicoNome(QString s) const
{
    return dati->nomeUnico(s);
}

void GraphController::c_costruisciQp(const PoligonoConvesso &p, QString nome, QPolygonF f)
{
    if(typeid(p) == typeid(Triangolo))
        calc->addTriangolo(new poligoniC(nome, f));
    else if(typeid(p) == typeid(Quadrilatero))
        calc->addQuadrilatero(new poligoniC(nome, f));
    else if(typeid(p) == typeid(Rettangolo))
        calc->addRettangolo(new poligoniC(nome, f));
    else if(typeid(p)==typeid(Quadrato))
        calc->addQuadrato(new poligoniC(nome, f));
}















