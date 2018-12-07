#ifndef GRAFO_CPP
#define GRAFO_CPP

#include "Grafo.h"

template <class T>
Grafo<T>::Grafo(int dir)
{
    this->vertices = new T[25];
    this->indices = new int[25];
    this->arestas = new MatrizEsparsa<int>(-1, 25, 25);
    this->indiceAtual = 0;
    this->ehDirecionado = dir;
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
int Grafo<T>::indiceDe(T vertice)
{
    int i;
    for (i = 0; i < indiceAtual; i++)
    {
        if (this->vertices[i] == vertice)
            break;
        if (i == indiceAtual)
            throw std::invalid_argument("Vertice v1 não existente");
    }
    return i;
}

template <class T>
void Grafo<T>::removeVertice(T vertice)
{
    if (this->temAresta(vertice))
        throw std::invalid_argument("Vertice possui arestas");

    int iVertc = this->indiceDe(vertice);

    for (int i = iVertc; i<this->indiceAtual; i++)
        this->vertices[i] = vertices[i+1];

    removerVerticeDasArestas(iVertc);

    vertices[--indiceAtual] = NULL;
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
int Grafo<T>::temAresta(T vertice)
{
   int iVertc = indiceDe(vertice);
   for (int j=0; j < this->indiceAtual; j++)
        if (this->arestas->get(iVertc, j) != -1)
            return 1;

   if (ehDirecionado)
   {
       for (int i= 0; i < this->indiceAtual; i++)
            if (this->arestas->get(i, iVertc) != -1)
                return 1;
   }

   return 0;
}

template <class T>
void Grafo<T>::removerVerticeDasArestas(int indice)
{
    for (int i = 0; i < indice; i++)
        for (int j = indice; j < this->indiceAtual; j++)
        {
            int val = arestas->get(i, j+1);
            this->arestas->put(val, i, j);
        }

    for (int i = indice; i < this->indiceAtual; i++)
        for (int j = 0; j < indice; j++)
        {
            int val = arestas->get(i+1, j);
            this->arestas->put(val, i, j);
        }

    for (int i = indice; i < this->indiceAtual; i++)
        for (int j = indice; j < this->indiceAtual; j++)
        {
            int val = arestas->get(i+1, j+1);
            this->arestas->put(val, i, j);
        }
}

#endif // GRAFO_CPP


