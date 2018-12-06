#ifndef MATRIZESPARSA_H
#define MATRIZESPARSA_H
#include "ArvoreAVL.h"

#include <iostream>
template<class T>
class MatrizEsparsa
{
    public:
        MatrizEsparsa<T>(T, int, int);

        void put(T, int, int);
        T get(int, int);

        int getLinhas();
        int getColunas();

        friend ostream &operator<<(ostream& out,  MatrizEsparsa<T>& matriz)
        {
            for (int i = 0; i < matriz.lins; i++)
            {
                for (int j = 0; j < matriz.cols; j++)
                    out << matriz.get(i, j);
                out << endl;
            }


            return out;
        }


    protected:

    private:
        ArvoreAVL<ArvoreAVL<T>*> *linhas;
        int lins;
        int cols;
        T valorPadrao;



};

#include "../src/MatrizEsparsa.cpp"
#endif // MATRIZESPARSA_H
