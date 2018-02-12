#include "graphcontroller.h"

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

// Inserisce nuova figura
void GraphController::c_addFigura(QString n, const vector<Vertice> &v)
{
    try
    {
        dati->costruisci(n, v);
        PoligonoConvesso *newP =  dati->getPoligono(n);

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
void GraphController::c_eliminaFigura(QString nome)
{
    dati->eliminaFigura(nome);
}

// Rimuovi tutte le figure
void GraphController::c_eliminaTutto()
{
    dati->eliminaTutto();
}

// Inserisce un nuovo vertice in una nuova figura
void GraphController::c_inserisciVertice(QString nome)
{
    calc->setDisabled(true);
    ins = new insertFigura(nome, this);
}

// Elimina un vertice
void GraphController::c_eliminaVertice(QString)
{

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

// Restituisce la somma dei campi info di una figura
double GraphController::c_getSomma(QString nome) const
{
    return dati->getSomma(nome);
}

double GraphController::c_getSottrazione(QString nome) const
{
    return dati->getSottrazione(nome);
}

void GraphController::c_stampaFigura(QString n)
{
    calc->infoPrint(QString::fromStdString(dati->getPoligono(n)->toString()));
}

void GraphController::c_enabledQd(bool)
{
    if(calc)
        calc->setEnabled(true);
}

PoligonoConvesso*& GraphController::c_getPoligono(QString n) const
{
    return dati->getPoligono(n);
}

vector<Vertice> &GraphController::c_getVertici(QString nome)
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















