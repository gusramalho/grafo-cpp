#ifndef ARVOREAVL_H
#define ARVOREAVL_H
#include "No.h"
#include <iostream>

template <class T>
class ArvoreAVL
{
    public:
        ArvoreAVL();

        void incluir(int, T info);

        void remover(int);

        int existe(int);

        T get(int);
        void setInfo(int, T);

        int altura();
        char* toString();
        char* toStringPorNvl();
        void test();

        friend ostream &operator<<(ostream& out,  ArvoreAVL<T>& avl)
        {
            out << avl.toStringPorNvl();
            return out;
        }



    protected:
    private:
        void incluir(T, No<T>*, No<T>*);
        int altura(No<T>*);



        No<T>* getMaior(No<T> *ptr);
        No<T>* getMenor(No<T> *ptr);

        void printaNo(No<T>*, char*);
        void printaPorNvl(No<T> *ptr, char**, int);


        No<T>* raiz;

        void calcEquilibrio(No<T>* ptr);
        void rotacionarEsq(No<T>* ,No<T>*);
        void rotacionarDir(No<T>* ,No<T>*);
        void rotacionarDuplaEsq(No<T>* ,No<T>*);
        void rotacionarDuplaDir(No<T>* ,No<T>*);

        void balancear();
        void balancear(No<T>* ptr, No<T>* ant);



};
#include "../src/ArvoreAVL.cpp"
#endif // ARVOREAVL_H
