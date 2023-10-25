#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

class Nodo{
    private:
    string codigo,articulo;
    int deposito1,deposito2,deposito3,deposito4,deposito5;
    Nodo *sgte;
    public:
    Nodo(){
        sgte=nullptr;
    }

    string getCodigo(){
        return codigo;
    }
    string getArticulo(){
        return articulo;
    }
    int getDeposito1(){
        return deposito1;
    }
    int getDeposito2(){
        return deposito2;
    }
    int getDeposito3(){
        return deposito3;
    }
    int getDeposito4(){
        return deposito4;
    }
    int getDeposito5(){
        return deposito5;
    }
    int getDepositoTotal(){
        return deposito1+deposito2+deposito3+deposito4+deposito5;
    }
    Nodo *getSiguiente(){
        return sgte;
    }

    void setSiguiente(Nodo *siguiente){
        this->sgte = siguiente;
    }
    
    void setDatos(string _codigo,string articulo,int deposito1,int deposito2,int deposito3,int deposito4,int deposito5){

    }
};
#endif NODO_H