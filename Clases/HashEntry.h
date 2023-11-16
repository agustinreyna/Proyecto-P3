#ifndef U05_HASH_HASHMAP_HASHENTRY_H_
#define U05_HASH_HASHMAP_HASHENTRY_H_
#include <vector>
using namespace std;

struct Articulo
{
    string codigo,grupo;
    vector<int> deposito;
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
        return valor.deposito[pos]; 
    }

    void setCodigo(string v) {
        valor.codigo = v;
    }

    void setGrupo(string v) {
        valor.grupo = v;
    }

    void imprimirDepositos(){
    
    if (!valor.deposito.empty()) {
    int tam = valor.deposito.size();

    for(int i=0;i<tam;i++){
        if(i==0)cout<<"Deposito Total "<<" :"<<valor.deposito[i]<<"->";
        else cout<<"Deposito "<<i<<" :"<<valor.deposito[i]<<"->";
    }
        cout<<"Vacio";
    }
    }

    HashEntry<K, T>* getNext() {
        return next;
    }

    void setNext(HashEntry<K, T>* n) {
        next = n;
    }
};

#endif // U05_HASH_HASHMAP_HASHENTRY_H_
