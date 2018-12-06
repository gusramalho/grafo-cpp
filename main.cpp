#include <iostream>
#include "Grafo.h"
using namespace std;

int main()
{
    Grafo<int>* g = new Grafo<int>();

    g->addVertice(40);
    g->addVertice(50);

    g->addAresta(40, 50, 3);
    cout << "Hello world!" << endl;
    return 0;
}
