#include "calcolatrice.h"
#include "ui_calcolatrice.h"

Calcolatrice::Calcolatrice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calcolatrice)
{
    ui->setupUi(this);

    setFixedSize(900, 750);

//    TRIANGOL0
    lt.setContentsMargins(0,0,0,0);
    vT = new viewTriangolo(ui->tabTriangolo);
    lt.addWidget(vT);
    ui->tabTriangolo->setLayout(&lt);

//    QUADRILATER0

//    RETTANGOL0

//    QUADRAT0

//    QPushButton

}

Calcolatrice::~Calcolatrice()
{
    delete ui;
}

void Calcolatrice::disabilitaView()
{

}

void Calcolatrice::abilitaView()
{

}

void Calcolatrice::nonSelez()
{
    QString s = "Seleziona una figura della finestra corrente!";
    ui->labRisultati->setStyleSheet("background-color: rgb(255, 255, 255); "
                                    "color: rgb(245, 0, 0); "
                                    "padding-left: 5px;");
    ui->labRisultati->setText(s);
}

QGraphicsView* Calcolatrice::getView() // view del poligono selezionato
{
    if(ui->Grafici->currentIndex()==0){ // triangoli
        if(!vT->scene()->selectedItems().isEmpty()){
            return vT;
        }
    }else if(ui->graficiQuad->currentIndex()==0){ // quadrilateri
        if(!vQr->scene()->selectedItems().isEmpty()){
            return vQr;
        }
    }else if(ui->graficiQuad->currentIndex()==1){ // rettangoli
        if(!vR->scene()->selectedItems().isEmpty()){
            return vR;
        }
    }else if(ui->graficiQuad->currentIndex()==2){ // quadrati
        if(!vQ->scene()->selectedItems().isEmpty()){
            return vQ;
        }
    }
    nonSelez();
    return nullptr;
}

void Calcolatrice::on_eliminaFigura_pressed()
{
    QGraphicsView *v = getView();
    if(v)
    {
        QGraphicsItem *f = v->scene()->selectedItems().first();

        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Elimina Figura");
        warning.setText("Sei sicuro di eliminare la figura selezionata?");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        warning.setDefaultButton(QMessageBox::Yes);
        int i = warning.exec();
        if(i == QMessageBox::Yes)
        {
            v->scene()->removeItem(f);
            delete f;
        }
    }
}

void Calcolatrice::on_inserisciFigura_pressed()
{

}

void Calcolatrice::on_eliminaVertice_pressed()
{

}

void Calcolatrice::on_Somma_pressed()
{
    QGraphicsView *v = getView();
    if(v)
    {
        QGraphicsItem *f = v->scene()->selectedItems().first();
//        double s = controller->getSomma();
//        ui->labRisultati->setText(QString::number(s));
    }
}


