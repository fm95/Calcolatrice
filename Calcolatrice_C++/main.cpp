#include "View/calcolatrice.h"
#include <QApplication>

#include "Model/triangolo.h"
#include "Model/quadrato.h"

// Francesco Minna 1103073

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Calcolatrice w;
    w.show();

    return a.exec();
}
