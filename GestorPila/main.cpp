#include <iostream>
#include "GestorPila.h"
using namespace std;

int main() {
    GestorPila gestor;

    
    stack<int> pilaInicial;
    pilaInicial.push(10);
    pilaInicial.push(20);
    pilaInicial.push(30);

    gestor.setPila(pilaInicial);

    
    gestor.insertar(40);

    
    stack<int> miPila = gestor.getPila();
    cout << "Elemento en la cima obtenido con getPila(): " << miPila.top() << endl;

    
    cout << "Pila actual: ";
    gestor.imprimir();
    cout << endl;

    
    cout << "¿Existe el 20? " << (gestor.buscar(20) ? "Si" : "No") << endl;

    
    gestor.eliminar();

    cout << "Pila tras eliminar: ";
    gestor.imprimir();
    cout << endl;

    return 0;
}