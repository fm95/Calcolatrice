#include "itemtriangoli.h"

itemTriangoli::itemTriangoli(QGraphicsItem *parent) : QGraphicsPolygonItem(parent)
{
    setFlag(QGraphicsItem::ItemIsSelectable, true);

    pressed=false;
}

bool itemTriangoli::getPressed() const
{
    return pressed;
}

/*
 *
 *if(Gettitolo()->text().isEmpty() ||  autore->text().isEmpty())
    {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
        QString s  = QString::fromUtf8((std::error_condition(std::errc::permission_denied).message()).c_str());
            warning.setWindowTitle(s);
            warning.setText("E' necessario compilare tutti i campi.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
        else{
            QMessageBox warning;
            warning.setIcon(QMessageBox::Question);
            warning.setWindowTitle("Modifica a libro");
            warning.setText("Sei sicuro di voler modificare il libro <b>"+Gettitolo()->text()+"</b>");
            warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            warning.setDefaultButton(QMessageBox::Yes);
            int ret = warning.exec();
            if(ret==QMessageBox::Yes) {
            emit modifica(Gettitolo()->text(),autore->text(),get_ID());
            }emit chiudi_dettagli_opera();
            }
 *
*/
