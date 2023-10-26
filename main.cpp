#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct Articulo
{
    std::string codigo, grupo;
    int deposito1, deposito2, deposito3, deposito4, deposito5;
};

struct stockArticulo
{
    std::string codigo, nombre, grupo;
};

using namespace std;

int main()
{
    map<string, Articulo> inventario;
    map<vector<int>,stockArticulo> inventarioStock;
    string nombre,line,stringNum;
    int k, totalarticulos = 0, totalarticulosdiferentes = 0,num;
    Articulo articulo;
    stockArticulo stocks;
    vector<int> depositos;

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
        articulo.deposito1=num;
        getline(ss, stringNum, ',');
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
        articulo.deposito5=num;

        stocks.grupo=articulo.grupo;
        stocks.nombre=nombre;
        stocks.codigo=articulo.codigo;
        depositos.push_back(articulo.deposito1 + articulo.deposito2 + articulo.deposito3 + articulo.deposito4 + articulo.deposito5);
        depositos.push_back(articulo.deposito1);
        depositos.push_back(articulo.deposito2);
        depositos.push_back(articulo.deposito3);
        depositos.push_back(articulo.deposito4);
        depositos.push_back(articulo.deposito5);

        totalarticulos += articulo.deposito1 + articulo.deposito2 + articulo.deposito3 + articulo.deposito4 + articulo.deposito5;
        totalarticulosdiferentes++;

        inventario.insert(make_pair(nombre, articulo));
        inventarioStock.insert(make_pair(depositos,stocks));
    }

    for (auto pair : inventario)
    {
        cout << "-----------------------------" << endl;
        cout << pair.first << endl;
    }
    cout << "-----------------------------" << endl;
    cout << "Total de articulos: " << totalarticulos << endl;
    cout << "Total de articulos diferentes: " << totalarticulosdiferentes << endl;




    
    return 0;
}



