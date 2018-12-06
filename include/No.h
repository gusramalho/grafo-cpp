#ifndef NO_H
#define NO_H

#include <iostream>
using namespace std;

template <class T>
class No
{
    public:
        No(int, T, No*, No*);
        No(int, T);
        ~No();

        void setChave(int);
        void setDir(No* ptr);
        void setEsq(No* ptr);
        void setEquilibrio(int);
        void setInfo(T);

        int getChave();
        No* getDir();
        No* getEsq();
        int getEquilibrio();
        T getInfo();

        int ehFolha();
        int estaEquilibrado();

        char* toString();

        friend ostream &operator<<(ostream& out, const No<T>& no)
        {
            out << no.info;
            return out;
        }





    protected:
    private:
        int chave;
        T info;
        int equilibrio;
        No* direita;
        No* esquerda;


};
#include "../src/No.cpp"
#endif // NO_H
