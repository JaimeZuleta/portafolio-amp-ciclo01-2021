#include "arbol.h"
#include <iostream>
#include <vector>
#include <string>


int main (int argc, char *argv[]){
	using namespace std;
	
	if (argc != 2){
		cout << "uso: " << argv[0] << " longitud_minima < cuentoCorto \n" << endl;
		return 1;
	}
	int longitudMinima = stoi(argv[1]);
	cout << longitudMinima << endl;
	ArbolBinarioBusqueda abb;
	string palabra;
	
	while(cin >> palabra){
		if (palabra.size() < longitudMinima) continue;
		if (!abb.contiene((palabra))) abb.poner(palabra, 1);
		else abb.poner(palabra, abb.obtener(palabra)+1);
	}
	vector<string> palabras = abb.claves();
	string palabrasMasFrecuente = "";
	for ( int i=0; i<palabra.size(); i++){
		string estaPalabra = palabras[i];
		if(abb.obtener(estaPalabra) > abb.obtener(palabra)+1);
		string palabrasMasFrecuente = estaPalabra;
	}
	cout << "Este archivo contiene " << palabras.size() << "palabras unicas." << endl;
	cout << "la palabra de almenos " << longitudMinima << " letras ";
	cout << "que mas se repite es " << palabrasMasFrecuente << endl;
	return 0;
	
}

