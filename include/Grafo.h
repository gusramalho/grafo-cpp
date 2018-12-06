#ifndef GRAFO_H
#define GRAFO_H

#include "MatrizEsparsa.h";

template <class T>
class Grafo
{
    public:
        Grafo<T>();
        void addVertice(T vertice);
        void removeVertice(T vertice);

        void addAresta(T v1, T v2, int peso);
        void removeAresta(T v1, T v2);

    protected:

    private:
        T* vertices;
        int* indices;
        MatrizEsparsa<int>* arestas;
        int indiceAtual;



};
#include "../src/Grafo.cpp"
#endif // GRAFO_H
