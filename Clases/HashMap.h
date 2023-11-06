#ifndef U05_HASH_HASHMAP_HASHMAP_H_
#define U05_HASH_HASHMAP_HASHMAP_H_

#include "HashEntry.h"

template <class K, class T>
class HashMap
{
private:

  HashEntry<K, T> **tabla;
  
  unsigned int tamanio;

  static unsigned int hashFunc(K clave);

  unsigned int (*hashFuncP)(K clave);

public:
  explicit HashMap(unsigned int k);

  HashMap(unsigned int k, unsigned int (*hashFuncP)(K clave));

  void get(K clave);

  int getDeposito(K clave,int pos);

  void put(K clave, T valor);

  void remove(K clave);

  ~HashMap();

  bool esVacio();

  void print();

  string* tosorted(int pos);

  string* tosortedMayor(int pos);
};

template <class K, class T>
HashMap<K, T>::HashMap(unsigned int k)
{
  tamanio = k;
  tabla = new HashEntry<K, T> *[tamanio];
  for (int i = 0; i < tamanio; i++)
  {
    tabla[i] = NULL;
  }
  hashFuncP = hashFunc;
}

template <class K, class T>
HashMap<K, T>::HashMap(unsigned int k, unsigned int (*fp)(K))
{
  tamanio = k;
  tabla = new HashEntry<K, T> *[tamanio];
  for (int i = 0; i < tamanio; i++)
  {
    tabla[i] = NULL;
  }
  hashFuncP = fp;
}

template <class K, class T>
HashMap<K, T>::~HashMap()
{
  for (int i = 0; i < tamanio; i++)
  {
    if (tabla[i] != NULL)
    {
      delete tabla[i];
    }
  }
}

template <class K, class T>
void HashMap<K, T>::get(K clave)
{
  unsigned int pos = hashFuncP(clave) % tamanio;
  HashEntry<K, T>* current = tabla[pos];
  if (tabla[pos] == NULL)
  {
    throw 404;
  }
  while(current->getClave()!=clave)current=current->getNext();

  cout << current->getClave() << "<->";
  cout << current->getCodigo() << "<->";
  cout << current->getGrupo() << "<->";
  current->imprimirDepositos();
  cout<<endl;
}

template <class K, class T>
int HashMap<K, T>::getDeposito(K clave,int dep)
{
  
  unsigned int pos = hashFuncP(clave) % tamanio;
  HashEntry<K, T>* current = tabla[pos];
  while(current->getClave()!=clave)current=current->getNext();
  return current->getDeposito(dep);
}


template <class K, class T>
void HashMap<K, T>::put(K clave, T valor)
{
  unsigned int pos = hashFuncP(clave) % tamanio;

  if (tabla[pos] == NULL) {
    tabla[pos] = new HashEntry<K, T>(clave, valor);
  } else {
    // Manejo de colisión: Agregar a la lista enlazada en esa posición
    HashEntry<K, T>* current = tabla[pos];
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    current->setNext(new HashEntry<K, T>(clave, valor));
  }
}

template <class K, class T>
void HashMap<K, T>::remove(K clave) {}

template <class K, class T>
bool HashMap<K, T>::esVacio()
{
  for (int i = 0; i < tamanio; i++)
  {
    if (tabla[i] != NULL)
    {
      return false;
    }
  }
  return true;
}

template <class K, class T>
unsigned int HashMap<K, T>::hashFunc(K clave)
{
  return (unsigned int)clave;
}

template <class K, class T>
void HashMap<K, T>::print()
{
  std::cout << "i" << " " << "Clave" << "\t\t" << "Valor" << std::endl;
  std::cout << "--------------------" << std::endl;

  for (int i = 0; i < tamanio; i++)
  {
    std::cout << "<---------->" <<i<< "<---------->" << endl;
    std::cout<<endl;
    HashEntry<K, T>* current = tabla[i];

    while (current != nullptr)
    {
      std::cout << current->getClave() << "<->";
      std::cout << current->getCodigo() << "<->";
      std::cout << current->getGrupo() << "<->";
      current->imprimirDepositos();
      
      std::cout <<endl;
      if(current->getNext()==nullptr)std::cout<<endl;
      current = current->getNext(); // Avanza al siguiente elemento en la lista enlazada, si existe

      
    }
   }
}

template <class K, class T>
string* HashMap<K, T>::tosorted(int pos){

    string* array = new string[tamanio];
    int* values = new int[tamanio];
    int index = 0;
    for(int i = 0; i < tamanio; i++){
      HashEntry<K, T>* current = tabla[i];
        while(current!=nullptr){
          array[index] = current->getClave();
          values[index] = current->getDeposito(pos);
          index++;
          current = current->getNext();
        }
    }

    for(int i = 0; i < index; i++){
        for(int j = 0; j < index; j++){
            if(values[i] < values[j]){
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;

                string temp2 = array[i];
                array[i] = array[j];
                array[j] = temp2;
            }
        }
    }
  return array;
}

template <class K, class T>
string* HashMap<K, T>::tosortedMayor(int pos){

    string* array = new string[tamanio];
    int* values = new int[tamanio];
    int index = 0;
    for(int i = 0; i < tamanio; i++){
      HashEntry<K, T>* current = tabla[i];
        while(current!=nullptr){
          array[index] = current->getClave();
          values[index] = current->getDeposito(pos);
          index++;
          current = current->getNext();
        }
    }

    for(int i = 0; i < index; i++){
        for(int j = 0; j < index; j++){
            if(values[i] > values[j]){
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;

                string temp2 = array[i];
                array[i] = array[j];
                array[j] = temp2;
            }
        }
    }
  return array;
}
#endif // U05_HASH_HASHMAP_HASHMAP_H_
