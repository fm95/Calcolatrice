#include "View/calcolatrice.h"
#include <QApplication>

#include "Model/triangolo.h"
#include "Model/quadrilatero.h"
#include "Model/quadrato.h"
#include "Model/rettangolo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calcolatrice w;
    w.show();

    return a.exec();
}
