#include <iostream>
#include "Grafo.h"
using namespace std;

int main()
{
    Grafo<int>* g = new Grafo<int>();

    g->addVertice(40);
    g->addVertice(50);
    g->addVertice(60);
    g->addVertice(80);
    g->addVertice(90);

    g->addAresta(40, 50, 3);
    g->addAresta(80, 90, 7);
    g->addAresta(40, 90, 5);
    //g->removeAresta(40, 50);
    g->removeVertice(60);

    cout << *g << endl;
    return 0;
}
