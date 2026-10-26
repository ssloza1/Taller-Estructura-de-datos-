#include <iostream>
#include <limits>
#include "GestorPila.h"
using namespace std;

int leerEntero(const string& mensaje) {
    int valor;

    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            return valor;
        }

        cout << "Entrada no valida. Escriba un numero entero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    GestorPila gestor;
    stack<int> pilaInicial;

    int cantidad = leerEntero("Cuantos datos desea ingresar? ");
    while (cantidad < 0) {
        cout << "La cantidad no puede ser negativa.\n";
        cantidad = leerEntero("Cuantos datos desea ingresar? ");
    }

    for (int i = 0; i < cantidad; ++i) {
        pilaInicial.push(leerEntero("Ingrese el dato " + to_string(i + 1) + ": "));
    }
    gestor.setPila(pilaInicial);

    int opcion;
    do {
        cout << "\n===== MENU DE LA PILA =====\n"
             << "1. Insertar un dato\n"
             << "2. Eliminar el dato de la cima\n"
             << "3. Mostrar la pila\n"
             << "4. Buscar un dato\n"
             << "5. Mostrar el dato de la cima\n"
             << "0. Salir\n";

        opcion = leerEntero("Seleccione una opcion: ");

        switch (opcion) {
        case 1:
            gestor.insertar(leerEntero("Ingrese el dato: "));
            cout << "Dato insertado correctamente.\n";
            break;

        case 2:
            if (gestor.getPila().empty()) {
                cout << "La pila esta vacia.\n";
            } else {
                gestor.eliminar();
                cout << "Dato eliminado correctamente.\n";
            }
            break;

        case 3:
            if (gestor.getPila().empty()) {
                cout << "La pila esta vacia.\n";
            } else {
                cout << "Pila actual: ";
                gestor.imprimir();
                cout << '\n';
            }
            break;

        case 4: {
            int dato = leerEntero("Ingrese el dato que desea buscar: ");
            cout << (gestor.buscar(dato) ? "El dato si existe en la pila.\n"
                                         : "El dato no existe en la pila.\n");
            break;
        }

        case 5:
            if (gestor.getPila().empty()) {
                cout << "La pila esta vacia.\n";
            } else {
                cout << "Dato en la cima: " << gestor.getPila().top() << '\n';
            }
            break;

        case 0:
            cout << "Programa finalizado.\n";
            break;

        default:
            cout << "Opcion no valida.\n";
        }
    } while (opcion != 0);

    return 0;
}
