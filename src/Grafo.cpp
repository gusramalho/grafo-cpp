#ifndef GRAFO_CPP
#define GRAFO_CPP

#include "Grafo.h"


template <class T>
Grafo<T>::Grafo()
{
    this->vertices = new T[100];
    this->indices = new int[100];
    this->arestas = new MatrizEsparsa<int>(-1, 100, 100);
    this->indiceAtual = 0;
}

template <class T>
void Grafo<T>::addVertice(T vertice)
{
    for (int i=0; i < indiceAtual; i++)
        if (vertices[i] == vertice)
            throw std::invalid_argument("Vertice ja existente");

    this->vertices[indiceAtual++] = vertice;
}

template <class T>
void Grafo<T>::addAresta(T v1, T v2, int peso)
{
    int indiceV1, indiceV2 = 0;
    for (indiceV1; indiceV1 < indiceAtual; indiceV1++)
    {
        if (this->vertices[indiceV1] == v1)
            break;
        if (indiceV1 == indiceAtual)
            throw std::invalid_argument("Vertice v1 não existente");
    }

    for (indiceV2; indiceV2 < indiceAtual; indiceV2++)
    {
        if (this->vertices[indiceV2] == v2)
            break;
        if (indiceV2 == indiceAtual)
            throw std::invalid_argument("Vertice v1 não existente");
    }

    if (this->arestas->get(indiceV1, indiceV2) != -1)
        throw std::invalid_argument("Aresta ja existente");

    this->arestas->put(peso, indiceV1, indiceV2);
    this->arestas->put(peso, indiceV2, indiceV1);
}






#endif // GRAFO_CPP


