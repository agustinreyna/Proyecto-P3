#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Articulo
{
    string codigo, grupo;
    int deposito1, deposito2, deposito3, deposito4, deposito5;
};

int main()
{
    map<string, Articulo> inventario;
    string nombre;
    int k,totalarticulos=0,totalarticulosdiferentes=0;
    Articulo articulo;
    do
    {
        cout << "-----------------------------" << endl;
        cout << "Decime el nombre" << endl;
        cin >> nombre;
        cout << "Decime el codigo" << endl;
        cin >> articulo.codigo;
        cout<<"Decime el grupo"<<endl;
        cin >> articulo.grupo;
        cout<<"Decime la cantidad en deposito 1"<<endl;
        cin >> articulo.deposito1;
        cout<<"Decime la cantidad en deposito 2"<<endl;
        cin >> articulo.deposito2;
        cout<<"Decime la cantidad en deposito 3"<<endl;
        cin >> articulo.deposito3;
        cout<<"Decime la cantidad en deposito 4"<<endl;
        cin >> articulo.deposito4;
        cout<<"Decime la cantidad en deposito 5"<<endl;
        cin >> articulo.deposito5;
        totalarticulos+=articulo.deposito1+articulo.deposito2+articulo.deposito3+articulo.deposito4+articulo.deposito5;
        totalarticulosdiferentes++;
        inventario.insert(make_pair(nombre,articulo));
        cout << "Si queres terminar de insertar articulos ingresa 0" << endl;
        cin >> k;
    } while (k != 0);

    for(auto pair : inventario){
        cout << "-----------------------------" << endl;
        cout<<pair.first<<endl;
    }
    cout << "-----------------------------" << endl;
    cout << "Total de articulos: "<<totalarticulos<< endl;
    cout << "Total de articulos diferentes: "<<totalarticulosdiferentes<< endl;
    return 0;
}
