#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <iostream>
using namespace std;

class Lista
{
private:
    Nodo *inicio;
public:
    Lista();

    Lista(const Lista &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(int pos,  int dato);

    void insertarUltimo(int dato);

    void remover(int pos);

    int getDato(int pos);

    void imprimir();

    void moverNodo(int pos);

    void vaciar();
};

Lista::Lista()
{
    inicio = nullptr;
}

Lista::Lista(const Lista &li)
{
    inicio = nullptr;
}

Lista::~Lista() {}

bool Lista::esVacia()
{
    return inicio == nullptr;
}

int Lista::getTamanio()
{
    Nodo *aux = inicio;
    int tam = 0;

    while (aux != nullptr)
    {
        aux = aux->getSiguiente();
        tam++;
    }
    return tam;
}

void Lista::insertar(int pos, int dato)
{
    Nodo *aux = inicio;
    int posActual = 0;
    Nodo *nuevo = new Nodo;
    nuevo->setDato(dato);

    if (pos == 0)
    {
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux != nullptr && posActual < pos - 1)
    {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr)
    {
        throw 404;
    }
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

void Lista::insertarUltimo(int dato)
{
    Nodo *aux = inicio;
    Nodo *nuevo = new Nodo;
    nuevo->setDato(dato);
    if (aux == nullptr)
    { // CASO EN EL QUE LA LISTA ESTE VACIA
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        cout<<"Se inserto "<<dato<<endl;
        return;
    }

    while (aux->getSiguiente() != nullptr)
    { // EL SIGUIENTE DEL AUXILIAR TIENE QUE SER SI O SI NULL
        aux = aux->getSiguiente();
    }
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

int Lista::getDato(int pos)
{
    Nodo *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos - 1)
    {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr)
    {
        throw 404;
    }

    return aux->getDato();
}

void Lista::imprimir()
{
    Nodo *aux = inicio;
    int i=1;
    while (aux != nullptr)
    {
        cout <<"Deposito "<<i<<": "<<aux->getDato() << "->";
        aux = aux->getSiguiente();
        i++;
    }
    cout << "NULL" << endl;
}

void Lista::moverNodo(int pos)
{
    Nodo *aux1 = inicio;
    Nodo *aux2 = inicio;
    int posActual = 0;
    while (aux1 != nullptr && posActual < pos)
    {
        posActual++;
        aux1 = aux1->getSiguiente();
    }
    posActual = 0;
    while (aux2 != nullptr && posActual < pos - 1)
    {
        posActual++;
        aux2 = aux2->getSiguiente();
    }
    aux2->setSiguiente(aux1->getSiguiente());
    aux1->setSiguiente(inicio);
    inicio = aux1;
}

void Lista::vaciar()
{
    Nodo *aux = inicio, *aBorrar;
    int posActual = 0;

    while (aux != nullptr)
    {
        aBorrar = aux;
        aux = aux->getSiguiente();
        delete aBorrar;
    }
    
    inicio = nullptr;
}
#endif LISTA_H
