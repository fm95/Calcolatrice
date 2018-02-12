#include "calcolatrice.h"
#include "ui_calcolatrice.h"

Calcolatrice::Calcolatrice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calcolatrice),
    ct(new GraphController(this)),
    msg(0),
    pS(0)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/Icone/logo.png"));
    setFixedSize(760, 750);
    setUpdatesEnabled(true);

//    ui->labRisultati + scrollbar

//    TRIANGOL0
    lt.setContentsMargins(0,0,0,0);
    vT = new GView(this);
    vT->setSceneRect(0,0,170,117);
    lt.addWidget(vT);
    ui->tabTriangolo->setLayout(&lt);

//    QUADRILATER0
    lQr.setContentsMargins(0,0,0,0);
    vQr = new GView(this);
    vQr->setSceneRect(0,0,170,109);
    lQr.addWidget(vQr);
    ui->tabQuadrilatero->setLayout(&lQr);

//    RETTANGOLO
    lR.setContentsMargins(0,0,0,0);
    vR = new GView(this);
    vR->setSceneRect(0,0,170,109);
    lR.addWidget(vR);
    ui->tabRettangolo->setLayout(&lR);

//    QUADRATO
    lQ.setContentsMargins(0,0,0,0);
    vQ = new GView(this);
    vQ->setSceneRect(0,0,170,109);
    lQ.addWidget(vQ);
    ui->tabQuadrato->setLayout(&lQ);

    connect(ui->InserisciFigura, SIGNAL(pressed()), this, SLOT(inserisciFigura_pressed()));
    connect(ui->EliminaFigura, SIGNAL(pressed()), this, SLOT(eliminaFigura_pressed()));
    connect(ui->EliminaTutto, SIGNAL(pressed()), this, SLOT(eliminaTutto_pressed()));
    connect(ui->Esci, SIGNAL(clicked(bool)), this, SLOT(close()));

    connect(ui->inserisciVertice, SIGNAL(pressed()), this, SLOT(inserisciVertice_pressed()));
    connect(ui->eliminaVertice, SIGNAL(pressed()), this, SLOT(eliminaVertice_pressed()));
    connect(ui->modificaInfo, SIGNAL(pressed()), this, SLOT(modificaInfo_pressed()));

    connect(ui->MaxInfo, SIGNAL(pressed()), this, SLOT(Max_pressed()));
    connect(ui->MinInfo, SIGNAL(pressed()), this, SLOT(Min_pressed()));
    connect(ui->AVGInfo, SIGNAL(pressed()), this, SLOT(AVG_pressed()));
    connect(ui->Somma, SIGNAL(pressed()), this, SLOT(Somma_pressed()));
    connect(ui->Sottrazione, SIGNAL(pressed()), this, SLOT(Sottrazione_pressed()));
    connect(ui->Apotema, SIGNAL(pressed()), this, SLOT(Apotema_pressed()));

}

Calcolatrice::~Calcolatrice()
{
    delete ui; // interfaccia
    if(!list.isEmpty())
        eliminaList(); // policoniC*

    delete ct; // controller e dati

    if(msg) delete msg; // qmessagebox
    delete vT;
    delete vQr; // view e scene
    delete vR;
    delete vQ;
    this->destroyed(this);
}

void Calcolatrice::closeEvent(QCloseEvent *event)
{
    if(isEnabled())
        QDialog::closeEvent(event);
    else // se e' aperta l'insert, l'evento viene ignorato
        event->ignore();
}

void Calcolatrice::mousePressEvent(QMouseEvent *)
{
    ui->labRisultati->clear(); // pulisce il label dei risultati
    deseleziona();
    if(ui->Grafici->currentIndex()==0) // triangolo
    {
        ui->inserisciVertice->setEnabled(true);
        ui->eliminaVertice->setEnabled(false);
        ui->eliminaVertice->setToolTip("Il triangolo e' il poligono convesso piu' piccolo!");
    }
    else if(ui->Grafici->currentIndex() == 1)// quadrilateri
    {
        ui->eliminaVertice->setEnabled(true);
        ui->inserisciVertice->setEnabled(false);
        ui->inserisciVertice->setToolTip("Il poligono con 5 lati non e' supportato!");
    }
}

void Calcolatrice::inserisciFigura_pressed()
{
    deseleziona();
    ct->c_inserisciFigura();
}

void Calcolatrice::eliminaFigura_pressed()
{
    if(list.isEmpty()) // non ci sono ancora figure
            errorPrint("vuoto");
    else if(pS!=0 && pS->isSelected())
    {
        if(msg)
            delete msg;
        msg = new QMessageBox;
        msg->setIcon(QMessageBox::Critical);
        msg->setWindowTitle("Elimina Figura");
        msg->setText("Sei sicuro di eliminare la figura selezionata?");
        msg->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msg->setButtonText(QMessageBox::Yes, tr("Si"));
        msg->setDefaultButton(QMessageBox::No);
        setEnabled(false); // disabilito la qdialog principale
        int i = msg->exec();
        if(i == QMessageBox::Yes)
        {
            ct->c_eliminaFigura(pS->getNome());
            elimina(pS->getNome());
            ui->labRisultati->clear();
            setEnabled(true);
        }
        else
            setEnabled(true);
    }
    else
        errorPrint("seleziona");
}

void Calcolatrice::eliminaTutto_pressed()
{
    if(list.isEmpty())
            errorPrint("vuoto");
    else
    {
        if(msg)
            delete msg;
        msg=new QMessageBox();
        msg->setIcon(QMessageBox::Critical);
        msg->setWindowTitle("Elimina figure");
        msg->setText("Sei sicuro di eliminare tutte le figure?");
        msg->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msg->setButtonText(QMessageBox::Yes, tr("Si"));
        msg->setDefaultButton(QMessageBox::Yes);
        setEnabled(false);
        int i = msg->exec();
        if(i == QMessageBox::Yes)
        {
            pS=0;
            ct->c_eliminaTutto();
            eliminaList();
            ui->labRisultati->clear();
            ui->Grafici->setCurrentIndex(0);
            setEnabled(true);
        }
        else
            setEnabled(true);
    }
}

void Calcolatrice::inserisciVertice_pressed()
{
    if(list.isEmpty())
        errorPrint("vuoto");
    else if(pS!=0 && pS->isSelected())
    {
        ct->c_inserisciVertice(pS->getNome());
    }
    else
        errorPrint("seleziona");
}

void Calcolatrice::eliminaVertice_pressed()
{
    if(list.isEmpty())
        errorPrint("vuoto");
    else if(pS!=0 && pS->isSelected())
    {
        ct->c_eliminaVertice(pS->getNome());
    }
    else
        errorPrint("seleziona");
}

void Calcolatrice::modificaInfo_pressed()
{
    if(list.isEmpty())
        errorPrint("vuoto");
    else if(pS!=0 && pS->isSelected())
    {
        ui->labRisultati->clear();
        ct->c_modificaInfo(pS->getNome());
    }
    else
        errorPrint("seleziona");
}

void Calcolatrice::Max_pressed()
{
    if(list.isEmpty())
        errorPrint("vuoto");
    else if(pS!=0 && pS->isSelected())
    {
        double s = ct->c_getMax(pS->getNome());
        ui->labRisultati->setText(QString::number(s));
    }
    else
        errorPrint("seleziona");
}

void Calcolatrice::Min_pressed()
{
    if(list.isEmpty())
        errorPrint("vuoto");
    else if(pS!=0 && pS->isSelected())
    {
        double s = ct->c_getMin(pS->getNome());
        ui->labRisultati->setText(QString::number(s));
    }
    else
        errorPrint("seleziona");
}

void Calcolatrice::AVG_pressed()
{
    if(list.isEmpty())
        errorPrint("vuoto");
    else if(pS!=0 && pS->isSelected())
    {
        double s = ct->c_getAVG(pS->getNome());
        ui->labRisultati->setText(QString::number(s));
    }
    else
        errorPrint("seleziona");
}

void Calcolatrice::Somma_pressed()
{
    if(list.isEmpty())
        errorPrint("vuoto");
    else if(pS!=0 && pS->isSelected())
    {
        double s = ct->c_getSomma(pS->getNome());
        ui->labRisultati->setText(QString::number(s));
    }
    else
        errorPrint("seleziona");
}

void Calcolatrice::Sottrazione_pressed()
{
    if(list.isEmpty())
        errorPrint("vuoto");
    else if(pS!=0 && pS->isSelected())
    {
        double s = ct->c_getSottrazione(pS->getNome());
        ui->labRisultati->setText(QString::number(s));
    }
    else
        errorPrint("seleziona");
}

void Calcolatrice::Apotema_pressed()
{
    if(list.isEmpty())
        errorPrint("vuoto");
    else if(pS!=0 && pS->isSelected())
    {
        double s = ct->c_getApotema(pS->getNome());
        ui->labRisultati->setText(QString::number(s));
    }
    else
        errorPrint("seleziona");
}

void Calcolatrice::deseleziona()
{
    if(pS)
    {
        pS->setSelected(false);
        pS=0;
    }
}

void Calcolatrice::cerca(const GView &v, const QPointF f)
{ // la view mi permette di cercare poligoni solo nella view dove ho clikkato, essendoci una lista unica
    for(auto it=list.begin(); !list.isEmpty() && it!=list.end(); ++it)
    {
        if((*it)->scene() == v.scene() && (*it)->getPol().containsPoint(f, Qt::WindingFill))
            seleziona(*it);
    }
}

void Calcolatrice::seleziona(poligoniC *&pC)
{
    if(pC!=0)
    {
        pS = pC;
        pS->setSelected(true);
        if(pC->getPol().size() == 3) // triangolo
        {
            ui->Grafici->setCurrentIndex(0);
            ui->inserisciVertice->setEnabled(true);
            ui->eliminaVertice->setEnabled(false);
        }
        else if(pC->getPol().size() == 4) // quadrilatero o >
        {
//            if(pC->getPol) // quadrato
//                attivo getApotema
//            {}
//            else
//            {
                ui->Grafici->setCurrentIndex(1);
                ui->eliminaVertice->setEnabled(true);
                ui->inserisciVertice->setEnabled(false);
                ui->Apotema->setEnabled(false);
//            }
        }
        ct->c_stampaFigura(pC->getNome());
    }
}

void Calcolatrice::addTriangolo(poligoniC *pC)
{
    list.push_front(pC);
    vT->scene()->addItem(pC);
    seleziona(pC);
    ui->Grafici->setCurrentIndex(0);
}

void Calcolatrice::addQuadrilatero(poligoniC *pC)
{
    list.push_front(pC);
    vQr->scene()->addItem(pC);
    seleziona(pC);
    ui->graficiQuad->setCurrentIndex(0);
}

void Calcolatrice::addRettangolo(poligoniC *pC)
{
    list.push_front(pC);
    vR->scene()->addItem(pC);
    seleziona(pC);
    ui->graficiQuad->setCurrentIndex(1);
}

void Calcolatrice::addQuadrato(poligoniC *pC)
{
    list.push_front(pC);
    vQ->scene()->addItem(pC);
    seleziona(pC);
    ui->graficiQuad->setCurrentIndex(2);
}

void Calcolatrice::infoPrint(QString s) const
{
//    if(s.length() > ui->labRisultati->)  SCROLL

    ui->labRisultati->setStyleSheet("background-color: rgb(255, 255, 255); "
                                    "padding-left: 5px;");
    ui->labRisultati->setText(s);
}

void Calcolatrice::errorPrint(QString s) const
{
    ui->labRisultati->setStyleSheet("background-color: rgb(255, 255, 255); "
                                    "color: rgb(245, 0, 0); "
                                    "padding-left: 5px;");
    if(s == "seleziona")
        s = "Seleziona una figura!";
    else if(s == "vuoto")
        s = "Non hai ancora inserito figure!";
    ui->labRisultati->setText(s);
}

void Calcolatrice::elimina(QString nome)
{
    pS->scene()->removeItem(pS);
    deseleziona();
    for(auto it=list.begin(); it!=list.end(); ++it)
    {
        if((*it)->getNome() == nome)
        {
            delete *it;
            it=list.erase(it);
            return;
        }
    }
}

void Calcolatrice::eliminaList()
{
    pS=0;
    for(auto it=list.begin(); it!=list.end();)
    {
        delete *it;
        it = list.erase(it);
    }
    list.clear();
}
