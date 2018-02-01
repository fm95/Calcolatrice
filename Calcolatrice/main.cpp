#include "View/calcolatrice.h"
#include <QApplication>

#include "Model/triangolo.h"
#include "Model/quadrilatero.h"
#include "Model/quadrato.h"
#include "Model/rettangolo.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calcolatrice w;
    w.show();

    Punto p1(1, 1);
    Punto p2(1, 5);
    Punto p3(5, 5);
    Punto p4(5, 1);

    Vertice v1(p1, 1);
    Vertice v2(p2, 2);
    Vertice v3(p3, 3);
    Vertice v4(p4, 4);

    vector<Vertice> v;
        v.push_back(v1);
        v.push_back(v2);
        v.push_back(v3);

    cout<<v1<<endl;

    Triangolo* t = new Triangolo("TEST :)", v);
    cout<<*t<<endl;

    return a.exec();
}
