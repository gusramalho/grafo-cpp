#ifndef GRAFO_H
#define GRAFO_H

#include "MatrizEsparsa.h";

template <class T>
class Grafo
{
    public:
        Grafo<T>();


    protected:

    private:
        T* vertices;
        MatrizEsparsa<int> arestas;

};

#endif // GRAFO_H
