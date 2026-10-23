# Taller-Estructura-de-datos-
#include <iostream>
#include <stack>
using namespace std;

stack<int> pila;  // pila que registra las llamadas pendientes

void mostrarPila() {
    stack<int> copia = pila;
    cout << "   Pila (cima -> base): ";
    while (!copia.empty()) {
        cout << copia.top() << " ";
        copia.pop();
    }
    cout << endl;
}

long long factorial(int n) {
    pila.push(n);                       // push: se apila la llamada
    cout << "push factorial(" << n << ")" << endl;
    mostrarPila();

    long long resultado;
    if (n <= 1) {
        resultado = 1;                  // caso base
    } else {
        resultado = n * factorial(n - 1);  // llamada recursiva
    }

    pila.pop();                         // pop: la llamada termina
    cout << "pop  factorial(" << n << ") devuelve " << resultado << endl;
    mostrarPila();
    return resultado;
}

int main() {
    cout << "Resultado final: " << factorial(4) << endl;
    return 0;
}
