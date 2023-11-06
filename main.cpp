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

void menu(){
    cout<<"~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Opcion 0: Salir del programa"<<endl;
    cout<<"Opcion 1: Imprimir hashmap"<<endl;
    cout<<"Opcion 2: Ver cantidad total de articulos diferentes"<<endl;
    cout<<"Opcion 3: Ver cantidad de total de articulos"<<endl;
    cout<<"Opcion 4: Ver listado de artículos con cantidad n o menos de stock"<<endl;
    cout<<"Opcion 5: Ver listado de artículos con cantidad n o menos de stock según un depósito"<<endl;
    cout<<"Opcion 6: Ver el stock total de cierto articulo"<<endl;
    cout<<"Opcion 7: Ver el stock de cierto artículo en un depósito"<<endl;
    cout<<"Opcion 8: Ver el listado de aquellos artículos cuyo stock es igual o supera el número n"<<endl;
}

int main()
{   
    HashMap<string,Articulo> tabla(300,hashFunc);
    //map<string, Articulo> inventario;
    
    string nombre,line,stringNum;
    char clave[100];
    int k,n,pos,index,totalarticulos = 0, totalarticulosdiferentes = 0,num,depositoTotal=0;
    Articulo articulo;
    string* arrayOrdenado;

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

    do{
        menu();
        cin>>k;
        system("cls");
        switch (k)
        {
        case 1:
            tabla.print();
            break;
        
        case 2:
            cout << "Total de articulos diferentes: " << totalarticulosdiferentes << endl;
            break;
        
        case 3:
            cout << "Total de articulos : " << totalarticulos << endl;
            break;
        
        case 4:
            cout<<"Decime cuanto es el minimo de stock :";
            cin>>n;
            arrayOrdenado=tabla.tosorted(0);
            index=0;
            while(tabla.getDeposito(arrayOrdenado[index],0)<=n){
            tabla.get(arrayOrdenado[index]);
            cout<<endl;
            index++;
            }
            break;
        
        case 5:
            cout<<"Decime cuanto es el minimo de stock :";
            cin>>n;
            cout<<"Decime en cual deposito(1,2,3,4,n) :";
            cin>>pos;
            arrayOrdenado=tabla.tosorted(pos);
            index=0;
            while(tabla.getDeposito(arrayOrdenado[index],pos)<=n){
            tabla.get(arrayOrdenado[index]);
            cout<<endl;
            index++;
            }
            break;
        
        case 6:
            cout << "Decime el nombre del articulo: ";
            cin.ignore();
            cin.getline(clave, 100);
            cout<<tabla.getDeposito(clave,0);
            cout<<endl;
            break;
        
        case 7:
            cout << "Decime el nombre del articulo: ";
            cin.ignore();
            cin.getline(clave, 100);
            cout<<"Decime el deposito: ";
            cin>>pos;
            cout<<tabla.getDeposito(clave,pos);
            cout<<endl;
            break;
        
        case 8:
            cout<<"Decime cuanto es el minimo de stock :";
            cin>>n;
            arrayOrdenado=tabla.tosortedMayor(0);
            index=0;
            while(tabla.getDeposito(arrayOrdenado[index],0)>=n){
            tabla.get(arrayOrdenado[index]);
            cout<<endl;
            index++;
            }
            break;
        
        default:
            break;
        }
    }while(k!=0);    

    return 0;
}
