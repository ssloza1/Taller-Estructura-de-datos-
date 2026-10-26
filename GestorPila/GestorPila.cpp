/***********************************************************************
 * Module:  GestorPila.cpp
 * Author:  Usuario
 * Modified: domingo, 25 de octubre de 2026 17:28:59
 * Purpose: Implementation of the class GestorPila
 ***********************************************************************/

#include "GestorPila.h"

////////////////////////////////////////////////////////////////////////
// Name:       GestorPila::getPila()
// Purpose:    Implementation of GestorPila::getPila()
// Return:     stack <int>
////////////////////////////////////////////////////////////////////////

stack <int> GestorPila::getPila(void)
{
   return pila;
}

////////////////////////////////////////////////////////////////////////
// Name:       GestorPila::setPila(stack <int> newPila)
// Purpose:    Implementation of GestorPila::setPila()
// Parameters:
// - newPila
// Return:     void
////////////////////////////////////////////////////////////////////////

void GestorPila::setPila(stack <int> newPila)
{
   pila = newPila;
}

////////////////////////////////////////////////////////////////////////
// Name:       GestorPila::GestorPila()
// Purpose:    Implementation of GestorPila::GestorPila()
// Return:     
////////////////////////////////////////////////////////////////////////

GestorPila::GestorPila()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       GestorPila::insertar(int valor)
// Purpose:    Implementation of GestorPila::insertar()
// Parameters:
// - valor
// Return:     void
////////////////////////////////////////////////////////////////////////

void GestorPila::insertar(int valor)
{
   stack<int> temp = getPila();
   temp.push(valor);
   setPila(temp);
}

////////////////////////////////////////////////////////////////////////
// Name:       GestorPila::eliminar()
// Purpose:    Implementation of GestorPila::eliminar()
// Return:     void
////////////////////////////////////////////////////////////////////////

void GestorPila::eliminar(void)
{
   stack<int> temp = getPila();
   if (!temp.empty()) {
       temp.pop();
       setPila(temp);
   }
}

////////////////////////////////////////////////////////////////////////
// Name:       GestorPila::imprimir()
// Purpose:    Implementation of GestorPila::imprimir()
// Return:     int
////////////////////////////////////////////////////////////////////////

int GestorPila::imprimir(void)
{
   stack<int> temp = getPila();
   if (temp.empty()) return 0; 
   
   int cima = temp.top();
   temp.pop();
   setPila(temp); 
   
   cout << cima << " "; 
   
   imprimir();      
   
   temp = getPila();
   temp.push(cima);     
   setPila(temp);
   
   return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       GestorPila::buscar(int objetivo)
// Purpose:    Implementation of GestorPila::buscar()
// Parameters:
// - objetivo
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool GestorPila::buscar(int objetivo)
{
   stack<int> temp = getPila();
   if (temp.empty()) return false;
   
   int cima = temp.top();
   if (cima == objetivo) return true; 
   
   temp.pop();
   setPila(temp); 
   
   bool encontrado = buscar(objetivo); 
   
   temp = getPila();
   temp.push(cima); 
   setPila(temp);
   
   return encontrado;
}