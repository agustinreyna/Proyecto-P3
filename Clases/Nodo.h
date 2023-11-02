#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;

class Nodo
{
private:
    int dato;
    Nodo *sgte;

public:
    int getDato()
    {
        return dato;
    }
    void setDato(int n)
    {
        dato = n;
    }
    Nodo *getSiguiente()
    {
        return sgte;
    }
    void setSiguiente(Nodo *next)
    {
        sgte = next;
    }
};
#endif //NODO_H
