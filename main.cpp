#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Clases/HashMap.h"
using namespace std;

unsigned int hashFunc(string clave)
{
    unsigned int hash = 0;
    for (char i : clave)
    {
        hash = hash * 31 + i;
    }
    return hash;
}

int main()
{   
    HashMap<string,Articulo> tabla(50,hashFunc);
    //map<string, Articulo> inventario;

    string nombre,line,stringNum;
    int k, totalarticulos = 0, totalarticulosdiferentes = 0,num;
    Articulo articulo;

    ifstream csv("csv.csv");

    while (getline(csv, line)) {
        stringstream ss(line);

        // Usamos getline con ',' como delimitador para obtener cada campo
        getline(ss, articulo.grupo, ',');
        getline(ss, articulo.codigo, ',');
        getline(ss, nombre, ',');
        getline(ss, stringNum, ',');
        if (!stringNum.empty()) {
        num = stoi(stringNum);
        }
        else num = 0;
        cout<<"Se guardo: "<<num<<endl;
        articulo.deposito->insertarUltimo(num);

        getline(ss, stringNum, ',');
        if (!stringNum.empty()) {
        num = stoi(stringNum);
        }
        else num = 0;
        cout<<"Se guardo: "<<num<<endl;
        articulo.deposito->insertarUltimo(num);

        getline(ss, stringNum, ',');
        if (!stringNum.empty()) {
        num = stoi(stringNum);
        }
        else num = 0;
        cout<<"Se guardo: "<<num<<endl;
        articulo.deposito->insertarUltimo(num);

        getline(ss, stringNum, ',');
        if (!stringNum.empty()) {
        num = stoi(stringNum);
        }
        else num = 0;
        cout<<"Se guardo: "<<num<<endl;
        articulo.deposito->insertarUltimo(num);

        getline(ss, stringNum, '\n');
        if (!stringNum.empty()) {
        num = stoi(stringNum);
        }
        else num = 0;
        cout<<"Se guardo: "<<num<<endl;
        articulo.deposito->insertarUltimo(num);

        totalarticulosdiferentes++;

        tabla.put(nombre,articulo);
        //articulo.deposito.vaciar();
    }

    tabla.print();
    cout << "Total de articulos diferentes: " << totalarticulosdiferentes << endl;

    return 0;
}

/*getline(ss, stringNum, ',');
        if (!stringNum.empty()) {
        num = stoi(stringNum);
        }
        else num = 0;
        articulo.deposito2=num;
        getline(ss, stringNum, ',');
        if (!stringNum.empty()) {
        num = stoi(stringNum);
        }
        else num = 0;
        articulo.deposito3=num;
        getline(ss, stringNum, ',');
        if (!stringNum.empty()) {
        num = stoi(stringNum);
        }
        else num = 0;
        articulo.deposito4=num;
        getline(ss, stringNum, '\n');
        if (!stringNum.empty()) {
        num = stoi(stringNum);
        }
        else num = 0;
        articulo.deposito5=num;*/

        //totalarticulos += articulo.deposito1 + articulo.deposito2 + articulo.deposito3 + articulo.deposito4 + articulo.deposito5;

 /*for (auto pair : inventario)
    {
        cout << "-----------------------------" << endl;
        cout << pair.first << endl;
    }
    cout << "-----------------------------" << endl;
    cout << "Total de articulos: " << totalarticulos << endl;
    */
