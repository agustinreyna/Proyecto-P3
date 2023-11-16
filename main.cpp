#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <ctime>
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
//g++ main.cpp -o main
//./main -file csv.csv

int main(int argc, char *argv[])
{   
    clock_t begin;
    cout << "Comenzando a medir Tiempo...\n" << endl;
    begin = clock();
    HashMap<string,Articulo> tabla(300,hashFunc);
    //map<string, Articulo> inventario;
    
    string nombre,line,stringNum,grupoViejo;
    char clave[100];
    int k,n,pos,index,totalarticulos = 0, totalarticulosdiferentes = 0,num,depositoTotal=0;
    Articulo articulo;
    string* arrayOrdenado;

    ifstream csv("csv.csv");

    while (getline(csv, line)) {
        stringstream ss(line);

        // Usamos getline con ',' como delimitador para obtener cada campo
        getline(ss,articulo.grupo, ',');
        if (!articulo.grupo.empty()) {
        grupoViejo=articulo.grupo;
        }
        else articulo.grupo=grupoViejo;
        getline(ss, articulo.codigo, ',');
        getline(ss, nombre, ',');
        getline(ss, stringNum, ',');
        if (!stringNum.empty()) {
        num = stoi(stringNum);
        }
        else num = 0;
        articulo.deposito.push_back(num);
        depositoTotal+=num;

        getline(ss, stringNum, ',');
        if (!stringNum.empty()) {
        num = stoi(stringNum);
        }
        else num = 0;
        articulo.deposito.push_back(num);
        depositoTotal+=num;

        getline(ss, stringNum, ',');
        if (!stringNum.empty()) {
        num = stoi(stringNum);
        }
        else num = 0;
        articulo.deposito.push_back(num);
        depositoTotal+=num;

        getline(ss, stringNum, ',');
        if (!stringNum.empty()) {
        num = stoi(stringNum);
        }
        else num = 0;
        articulo.deposito.push_back(num);
        depositoTotal+=num;

        getline(ss, stringNum, '\n');
        if (!stringNum.empty()) {
        num = stoi(stringNum);
        }
        else num = 0;
        articulo.deposito.push_back(num);
        depositoTotal+=num;
        articulo.deposito.insert(articulo.deposito.begin(),depositoTotal);

        totalarticulosdiferentes++;

        tabla.put(nombre,articulo);
        articulo.deposito.clear();
        totalarticulos+=depositoTotal;
        depositoTotal=0;

    }
     clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
    cout << " * Tiempo de Ejecucion * " << endl;
    cout << elapsed_secs << endl;
    bool opcionEncontrada = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-imprimirPrimeraMitad") == 0) {
            //cout << "\n Nombre del Archivo: " << argv[i + 1] << endl;
            tabla.printPrimeraMitad();
            opcionEncontrada = true;
        } else if (strcmp(argv[i], "-imprimirSegundaMitad") == 0) {
            tabla.printSegundaMitad();
            opcionEncontrada = true;
        } else if (strcmp(argv[i], "-cantTotalArtDif") == 0) {
            cout << "Total de articulos diferentes: " << totalarticulosdiferentes << endl;
            opcionEncontrada = true;
        } else if (strcmp(argv[i], "-cantTotalArt") == 0) {
            cout << "Total de articulos : " << totalarticulos << endl;
            opcionEncontrada = true;
        } else if (strcmp(argv[i], "-min_stock") == 0) {
            int minStock;
            stringstream(argv[i + 1]) >> minStock;
            arrayOrdenado=tabla.ordenarMenor(0);
            index=0;
            while(tabla.getDeposito(arrayOrdenado[index],0)<=minStock){
            tabla.get(arrayOrdenado[index]);
            cout<<endl;
            index++;
            }
            opcionEncontrada = true;
        } else if (strcmp(argv[i], "-min_stock_deposito") == 0) {
            int minStock, deposito;
            stringstream(argv[i + 1]) >> minStock;
            stringstream(argv[i + 2]) >> deposito;
            arrayOrdenado=tabla.ordenarMenor(deposito);
            index=0;
            while(tabla.getDeposito(arrayOrdenado[index],deposito)<=minStock){
            tabla.get(arrayOrdenado[index]);
            cout<<endl;
            index++;
            }
            opcionEncontrada = true;
        } else if (strcmp(argv[i], "-stock_art") == 0) {
            cout<<tabla.getDeposito(argv[i + 1],0);
            cout<<endl;
            opcionEncontrada = true;
        } else if (strcmp(argv[i], "-stock_art_dep") == 0) {
            int deposito;
            stringstream(argv[i + 2]) >> deposito;
            cout<<tabla.getDeposito(argv[i + 1],deposito);
            cout<<endl;
            opcionEncontrada = true;
        } else if (strcmp(argv[i], "-max_stock") == 0) {
            int maxStock;
            stringstream(argv[i + 1]) >> maxStock;
            arrayOrdenado=tabla.ordenarMayor(0);
            index=0;
            while(tabla.getDeposito(arrayOrdenado[index],0)>=maxStock){
            tabla.get(arrayOrdenado[index]);
            cout<<endl;
            index++;
            }
            opcionEncontrada = true;
        }
    }
    if (!opcionEncontrada) {
        cout << "ARGUMENTO NO VALIDO" << endl;
    }
    
    return 0;
}