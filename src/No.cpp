#ifndef NO_CPP
#define NO_CPP


#include "No.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

template <class T>
No<T>::No(int chave, T info)
{
    this->chave = chave;
    this->info = info;
    this->esquerda = NULL;
    this->direita = NULL;
    this->equilibrio = 0;
}

template <class T>
No<T>::No(int chave, T info, No* esq, No* dir)
{
    this->chave = chave;
    this->info = info;
    this->esquerda = esq;
    this->direita = dir;
}

template <class T>
No<T>::~No()
{
    this->info = NULL;
    delete this->esquerda;
    delete this->direita;
}


template <class T>
void No<T>::setDir(No* ptr)
{
    this->direita = ptr;
}

template <class T>
void No<T>::setEsq(No* ptr)
{
    this->esquerda = ptr;
}

template <class T>
No<T>* No<T>::getDir()
{
    return this->direita;
}

template <class T>
No<T>* No<T>::getEsq()
{
    return this->esquerda;
}

template <class T>
T No<T>::getInfo()
{
    return this->info;
}

template <class T>
void No<T>::setInfo(T info)
{
    this->info = info;
}

template <class T>
int No<T>::ehFolha()
{

    return  this->esquerda == NULL && this->direita == NULL;
}

template <class T>
int No<T>::getEquilibrio()
{
    return this->equilibrio;
}

template <class T>
void No<T>::setEquilibrio(int e)
{
    this->equilibrio = e;
}

template <class T>
int No<T>::estaEquilibrado()
{
    return this->equilibrio >= -1 || this->equilibrio <= 1;
}


template <class T>
ostream& operator<<(ostream& out, const No<T>& no)
{

}

template <class T>
char* No<T>::toString()
{
    char* ret = new char[10];
    strcpy(ret, "");
    sprintf(ret, "%d", this->info);
    return ret;
}


template <class T>
int No<T>::getChave()
{
    return this->chave;
}

template <class T>
void No<T>::setChave(int chave)
{
    this->chave = chave;
}



#endif



