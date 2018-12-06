#ifndef MATRIZESPARSA_CPP
#define MATRIZESPARSA_CPP


#include "MatrizEsparsa.h"

template<class T>
MatrizEsparsa<T>::MatrizEsparsa(T vp, int i, int j)
{
    this->linhas = new ArvoreAVL<ArvoreAVL<int>*>();
    this->lins = i;
    this->cols = j;
    this->valorPadrao = vp;
}

template<class T>
T MatrizEsparsa<T>::get(int i, int j)
{
    if (!this->linhas->existe(i))
        return this->valorPadrao;

    ArvoreAVL<int>* colunas = linhas->get(i);

    if (!colunas->existe(j))
        return this->valorPadrao;

    return colunas->get(j);
}

template<class T>
void MatrizEsparsa<T>::put(T info, int i, int j)
{
     if (!this->linhas->existe(i) && info != valorPadrao)
     {
         ArvoreAVL<T> *coluna = new ArvoreAVL<T>();
         coluna->incluir(j, info);
         this->linhas->incluir(i, coluna);
     }
     else
     {
          ArvoreAVL<T> *coluna = linhas->get(i);

          int existe = coluna->existe(j);

          if (existe && info == valorPadrao)
          {
              coluna->remover(j);

              if (coluna->altura() == 0)
                linhas->remover(i);
          }
          else
          if (existe && info != valorPadrao)
              coluna->setInfo(j, info);
          else
          if (!existe && info != valorPadrao)
              coluna->incluir(j, info);

     }
}

#endif
