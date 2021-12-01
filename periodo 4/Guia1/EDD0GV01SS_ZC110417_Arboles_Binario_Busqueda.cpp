#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class ArbolBinaarioBusqueda; 

class NodoArbol{
	friend class ArbolBinarioBusqueda;
	private:
		string clave;
		int vector;
		NodoArbol *izq;
		NodoArbol *der;
};

