/***********************************************************************
 * Module:  GestorPila.h
 * Author:  Usuario
 * Modified: domingo, 25 de octubre de 2026 17:28:59
 * Purpose: Declaration of the class GestorPila
 ***********************************************************************/

#if !defined(__Class_Diagram_1_GestorPila_h)
#define __Class_Diagram_1_GestorPila_h

#include <iostream>
#include <stack>
using namespace std;

class GestorPila
{
public:
   stack <int> getPila(void);
   void setPila(stack <int> newPila);
   GestorPila();
   void insertar(int valor);
   void eliminar(void);
   int imprimir(void);
   bool buscar(int objetivo);

protected:
private:
   stack <int> pila;
};

#endif