#ifndef GRAFO_H
#define GRAFO_H

#include "MatrizEsparsa.h";
#include <iostream>
template <class T>
class Grafo
{
    public:

        Grafo<T>(int);
        void addVertice(T vertice);
        void removeVertice(T vertice);

        void addAresta(T v1, T v2, int peso);
        void removeAresta(T v1, T v2);

        friend ostream &operator<<(ostream& out, Grafo<T>& grafo)
        {
            out << "Indice atual: " << grafo.indiceAtual << endl;
            out << "Vertices: ";
            for (int i=0; i<grafo.indiceAtual; i++)
            {
                out << grafo.vertices[i];
                if (i != grafo.indiceAtual - 1)
                    out << ", ";
            }
            out << endl;

            out << endl;
            out << "Arestas: " << endl;

            for (int i=0; i<grafo.indiceAtual+1; i++)
                for (int j=0; j<grafo.indiceAtual+1; j++)
                {
                    int aresta = grafo.arestas->get(i,j);
                    if (aresta != -1)
                    {
                        out << grafo.vertices[i];
                        out << " ----> ";
                        out << grafo.vertices[j];
                        out << " peso: ";
                        out << aresta << endl;
                    }
                }
            out << endl;

            out << endl;

            out << *grafo.arestas << endl;
            return out;
        }

    protected:

    private:
        T* vertices;
        int* indices;
        MatrizEsparsa<int>* arestas;
        int ehDirecionado;

        int indiceAtual;
        int indiceDe(T vertice);
        int temAresta(T vertice);
        void removerVerticeDasArestas(int);


};
#include "../src/Grafo.cpp"
#endif // GRAFO_H
