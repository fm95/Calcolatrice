#include "insertfigura.h"
#include "ui_insertfigura.h"

// Inserimento di una nuova figura
insertFigura::insertFigura(GraphController *g, QWidget *parent) :
    ui(new Ui::insertFigura),
    ct(g)
{
    ui->setupUi(this);
    setParent(parent);
    setAttribute(Qt::WA_DeleteOnClose); // elimina il qdialog alla chiusura

    setWindowTitle(QString("Inserisci nuova figura"));
    setFixedSize(430, 230);

    ui->i_Nome->setMaxLength(14);
    ui->i_nLati->setMaxLength(1);
    ui->i_X->setMaxLength(3);
    ui->i_Y->setMaxLength(3);
    ui->i_Info->setMaxLength(10);

    connect(ui->Avanti, SIGNAL(clicked()), this, SLOT(on_Avanti_pressed()));
    connect(ui->Annulla, SIGNAL(pressed()),this, SLOT(close()));
    connect(ui->Conferma, SIGNAL(clicked()), this, SLOT(on_Conferma_pressed()));

    show();
}

// Inserisce un vertice in una figura gia' esistente e crea la nuova figura risultante
insertFigura::insertFigura(QString nome, GraphController *g, QWidget *parent) :
    ui(new Ui::insertFigura),
    ct(g)
{
    ui->setupUi(this);
    setParent(parent);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle(QString("Inserisci nuovo vertice"));
    setFixedSize(430, 230);    

    buildV = ct->c_getVertici(nome); // copia
    ui->i_Nome->setMaxLength(14); // va inserito un nuovo nome
    ui->i_nLati->setText(QString::number(buildV.size()+1)); // # di vertici finale
    ui->i_nLati->setReadOnly(true);
    ui->error->setText(QString("Inserisci il nuovo vertice!"));

    connect(ui->Avanti, SIGNAL(clicked()), this, SLOT(on_Avanti_pressed()));
    connect(ui->Annulla, SIGNAL(pressed()),this, SLOT(close()));
    connect(ui->Conferma, SIGNAL(clicked()), this, SLOT(on_Conferma_pressed()));

    show();
}

// Elimina un vertice dalla figura
insertFigura::insertFigura(unsigned int, QString nome, GraphController *g, QWidget *parent) :
    ui(new Ui::insertFigura),
    ct(g)
{
    ui->setupUi(this);
    setParent(parent);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle(QString("Elimina un vertice"));
    setFixedSize(430, 230);

    buildV = ct->c_getVertici(nome); // copia
    ui->i_Nome->setMaxLength(14); // va inserito un nuovo nome
    ui->i_nLati->setText(QString::number(buildV.size()-1)); // # di vertici finale
    ui->i_nLati->setReadOnly(true);

    ui->i_X->setText(QString::number(buildV[0].getX()));
    ui->i_X->setReadOnly(true);
    ui->i_Y->setText(QString::number(buildV[0].getY()));
    ui->i_Y->setReadOnly(true);

    ui->Avanti->setEnabled(false);
    ui->error->setText(QString("Seleziona un vertice da eliminare!"));
    ui->Conferma->setText("Elimina");

    connect(ui->Annulla, SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->Conferma, SIGNAL(clicked()), this, SLOT(on_Conferma_pressed()));

    show();
}

// Modifica Info di un vertice
insertFigura::insertFigura(QString nome, double, GraphController *g, QWidget *parent) :
    ui(new Ui::insertFigura),
    ct(g),
    pos(0), inf(0)
{
    ui->setupUi(this);
    setParent(parent);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle(QString("Modifica info di un vertice"));
    setFixedSize(430, 230);

    buildV = ct->c_getVertici(nome); // copia

    ui->i_Nome->setText(nome); // nome della figura
    ui->i_Nome->setReadOnly(true);

    ui->i_nLati->setText(QString::number(buildV.size())); // # di vertici
    ui->i_nLati->setReadOnly(true);

    ui->i_X->setText(QString::number(buildV[pos].getX()));
    ui->i_X->setReadOnly(true);
    ui->i_Y->setText(QString::number(buildV[pos].getY()));
    ui->i_Y->setReadOnly(true);

    ui->i_Info->setText(QString::number(buildV[pos].getInfo())); // da modificare

    ui->Conferma->setText(QString("Modifica"));
    connect(ui->Annulla, SIGNAL(pressed()),this, SLOT(close()));
    connect(ui->Conferma, SIGNAL(pressed()), this, SLOT(on_Conferma_pressed()));
    connect(ui->Avanti, SIGNAL(pressed()), ui->i_Info, SLOT(on_Avanti_pressed()));

    show();
}

// Distruttore
insertFigura::~insertFigura()
{
    ct->c_enabledQd(true); // riabilito la calcolatrice
    delete ui;
//    if(!costruito)
//    {
        for(auto it=buildV.begin(); it!=buildV.end();)
            it = buildV.erase(it);
        buildV.clear();
//    }
    destroyed(this);
}

// Close Event
void insertFigura::closeEvent(QCloseEvent *event)
{
    event->accept(); // chiama il distruttore
}

void insertFigura::on_Avanti_pressed()
{
    if(pos==-1 && inf==-1)
    {
        if(ui->i_X->isEnabled())
            checkVertice();
        if(ui->i_nLati->isEnabled())
            checknLati();
        if(ui->i_Nome->isEnabled())
            checkNome();
    }
    else // devo modificare info di un vertice
    {
        if(buildV[pos].getInfo() != ui->i_Info->text().toDouble()) // e' stata aggiornata l'info
        {
//            if(check campo info)
            ui->Avanti->setEnabled(false);
//            else
//                print errore
        }
        else
        {
            pos++; // aumento la posizione
            if(pos==buildV.size()) // ricomincio il giro
                pos=0;
            ui->i_X->setText(QString::number(buildV[pos].getX())); // aggiorno i punti
            ui->i_Y->setText(QString::number(buildV[pos].getY()));
            ui->i_Info->setText(QString::number(buildV[pos].getInfo()));
        }
    }
}

void insertFigura::on_Conferma_pressed()
{
    if(!ui->Avanti->isEnabled()) // significa che ho inserito il nome, il #lati e tutti i vertici
    {
        if(pos==-1 && inf==-1) // allora devo costruire una nuova figura o inserire un vertice
            ct->c_addFigura(ui->i_Nome->text(), buildV); // costruisco il nuovo poligono
        else if(inf==-1) // allora devo eliminare un vertice
            ct->c_eliminaVertice(ui->i_Nome->text());
        else if(inf==0)// allora devo modificare un info
            ct->c_aggiornaInfo(ui->i_Nome->text(), pos, ui->i_Info->text().toDouble());
        close();
    }
    else
        ui->error->setText(QString("Compila tutti i campi correttamente!"));
}

// Controlli input
bool insertFigura::checkNome()
{ // il nome deve iniziare con una lettera, e puo' contenere numeri. max length 14 (min 1)
    if(ui->i_Nome->isEnabled())
    {
        if(ui->i_Nome->text().isEmpty())
        {
            ui->error->setText(QString("Inserisci il nome!"));
            return false;
        }
        else if(ct->c_getUnicoNome(ui->i_Nome->text()))
        {
            QRegExp rx("([A-Za-z]+[0-9]*){1,14}");
            if(rx.exactMatch(ui->i_Nome->text()))
            {
                ui->i_Nome->setReadOnly(true);
                return true;
            }
            else
            {
                ui->error->setText(QString("Inserisci un nome valido!"));
                return false;
            }
        }
        else
        {
            ui->error->setText(QString("Esiste gia' una figura con questo nome!"));
            return false;
        }
    }
    else
        return true;
}

bool insertFigura::checknLati()
{ // 3 o 4 lati
    if(ui->nLati->isEnabled() && checkNome())
    {
        if(ui->i_nLati->text().isEmpty())
        {
            ui->error->setText(QString("Inserisci il numero di lati!"));
            return false;
        }
        else
        {
            QRegExp l("[34]{1}"); // va modificato se viene estesa la gerarchia
            if(l.exactMatch(ui->i_nLati->text()))
            {
                ui->i_nLati->setReadOnly(true);
                return true;
            }
            else
            {
                ui->error->setText(QString("Il numero di lati puo' essere 3 o 4!"));
                return false;
            }
        }
    }
    else
        return true;
}

bool insertFigura::checkVertice()
{ // Range: X(0,160) e Y(0,105), e Info double +/- di max 10 cifre
    if(ui->i_X->isEnabled() && checkNome() && checknLati())
    {
        if(ui->i_X->text().isEmpty() || ui->i_Y->text().isEmpty() ||
                ui->i_Info->text().isEmpty())
        {
            ui->error->setText(QString("Inserire coordinate e info!"));
            return false;
        }
        else
        {
            QRegExp xy("((?!0\\d)\\d{1,6}(\\.\\d{1,6})?)"); // per X e Y
            if(xy.exactMatch(ui->i_X->text()) && xy.exactMatch(ui->i_Y->text()))
            {
                if(ui->i_X->text().toDouble()<160 && ui->i_Y->text().toDouble()<105) // max x e max y nel piano cartesiano
                {
                    QRegExp i("(|-)((?!0\\d)\\d{1,7}(\\.\\d{1,3})?)"); // per campo Info
                    if(i.exactMatch(ui->i_Info->text()))
                    {
                        if(ui->i_Info->text().toDouble() == -0) // non viene verificato dalla regexc
                            ui->i_Info->setText("0");
                        double x = ui->i_X->text().toDouble();
                        double y = ui->i_Y->text().toDouble();
                        double info = ui->i_Info->text().toDouble();
                        buildV.push_back(Vertice(x,y,info));
                        unsigned int i = ui->i_nLati->text().toInt();
                        if(buildV.size() == i) // se ho inserito l'ultimo vertice
                        {
                            ui->i_X->setEnabled(false);
                            ui->i_Y->setEnabled(false);
                            ui->i_Info->setEnabled(false);
                            ui->Avanti->setEnabled(false);
                            ui->error->clear();
                            ui->error->setEnabled(false);
                        }
                        ui->i_X->clear();
                        ui->i_Y->clear();
                        ui->i_Info->clear();
                        return true;
                    }
                    else
                    {
                        ui->error->setText(QString("Campo info non valido!"));
                        return false;
                    }
                }
                else
                {
                    ui->error->setText(QString("Il vertice piu' grande nel piano e' (135,105)!"));
                    return false;
                }
            }
            else
            {
                ui->error->setText(QString("Inserire dei valori corretti per X e Y!"));
                return false;
            }
        }
    }
    else
        return true;
}
