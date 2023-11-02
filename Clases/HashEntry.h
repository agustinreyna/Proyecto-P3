#ifndef U05_HASH_HASHMAP_HASHENTRY_H_
#define U05_HASH_HASHMAP_HASHENTRY_H_
#include "Lista.h"
using namespace std;

struct Articulo
{
    string codigo,grupo;
    Lista deposito;
};

template <class K, class T>
class HashEntry {
private:
    string clave;
    Articulo valor;
    HashEntry<string, Articulo>* next; 

public:
    HashEntry(string c, Articulo v) : clave(c), valor(v), next(nullptr) {}

    string getClave() {
        return clave;
    }

    void setClave(string c) {
        clave = c;
    }

    string getCodigo() {
        return valor.codigo;
    }

    string getGrupo() {
        return valor.grupo;
    }

    int getDeposito(int pos){
        return valor.deposito.getDato(pos); 
    }

    void setCodigo(string v) {
        valor.codigo = v;
    }

    void setGrupo(string v) {
        valor.grupo = v;
    }

    void imprimirDepositos(){
        valor.deposito.imprimir();
    }

    void setDeposito(int v) {
        valor.deposito.insertarUltimo(v);
    }

    HashEntry<K, T>* getNext() {
        return next;
    }

    void setNext(HashEntry<K, T>* n) {
        next = n;
    }
};

#endif // U05_HASH_HASHMAP_HASHENTRY_H_
