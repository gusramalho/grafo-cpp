#ifndef GRAFO_CPP
#define GRAFO_CPP

#include "Grafo.h"

template <class T>
Grafo<T>::Grafo(int dir)
{
    this->vertices = new T[10];
    this->indices = new int[10];
    this->arestas = new MatrizEsparsa<int>(-1, 10, 10);
    this->indiceAtual = 0;
    this->ehDirecionado = dir;
}

template <class T>
void Grafo<T>::addVertice(T vertice)
{
    for (int i=0; i < indiceAtual; i++)
        if (vertices[i] == vertice)
            throw std::invalid_argument("Vertice ja existente");

    this->indices[indiceAtual] = indiceAtual;
    this->vertices[indiceAtual++] = vertice;
}

template <class T>
int Grafo<T>::indiceDe(T vertice)
{
    int i;
    for (i = 0; i < indiceAtual; i++)
    {
        if (this->vertices[i] == vertice)
            break;
        if (i == indiceAtual)
            throw std::invalid_argument("Vertice nao existente");
    }
    return indices[i];
}

template <class T>
T Grafo<T>::getVertice(int i)
{
    int j;
    for (j = 0; j < indiceAtual; j++)
    {
        if (this->indices[j] == i)
            break;
        if (j == indiceAtual)
            throw std::invalid_argument("Vertice nao existente");
    }
    return vertices[j];
}

template <class T>
void Grafo<T>::removeVertice(T vertice)
{
    int iVertc = this->indiceDe(vertice);

    for (int i = iVertc; i<this->indiceAtual; i++)
    {
        this->vertices[i] = vertices[i+1];
        this->indices[i] = indices[i+1];
    }

    vertices[--indiceAtual] = NULL;
    indices[indiceAtual] = NULL;

    removeArestasDoVertice(iVertc);


}

template <class T>
void Grafo<T>::addAresta(T vOrigem, T vDestino, int peso)
{
    int origem = indiceDe(vOrigem);
    int destino = indiceDe(vDestino);

    if (this->arestas->get(origem, destino) != -1)
        throw std::invalid_argument("Aresta ja existente");

    this->arestas->put(peso, origem, destino);

    if (!ehDirecionado)
        this->arestas->put(peso, destino, origem);
}

template <class T>
void Grafo<T>::removeAresta(T vOrigem, T vDestino)
{
    int origem = indiceDe(vOrigem);
    int destino = indiceDe(vDestino);

    if (this->arestas->get(origem, destino) == -1)
        throw std::invalid_argument("Aresta nao existente");

    this->arestas->put(-1, origem, destino);

    if (!ehDirecionado)
        this->arestas->put(-1, destino, origem);
}

template <class T>
void Grafo<T>::removeArestasDoVertice(int i)
{
    for (int j=0; j < indiceAtual; j++)
    {
        if (j != i)
        {
            arestas->put(-1, i, j);
            arestas->put(-1, j, i);
        }
    }
}

#endif // GRAFO_CPP


