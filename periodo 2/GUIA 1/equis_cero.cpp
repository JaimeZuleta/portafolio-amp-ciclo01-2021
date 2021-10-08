
//Jaime Esau Zuleta Calzada 
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

const int LADO = 3;

//prototpo de funciones
void imprimirTablero(char tablero[][LADO]);
int marcarCasillaJugador(char tablero[][LADO]);
int leerNumero (string indicacion, string mensajeError, int min, int max);
int marcarCasillaCompuradora(char tablero[][LADO]);
char ganadorFilas(char tablero[][LADO]);
char ganadorColumnas(char tablero[][LADO]);
char ganadorDiagonales(char tablero[][LADO]);
char determinarGanador(char tablero[][LADO]);
void jugar();

int main (){
	char jugarDeNuevo;
	srand(time(0));// inicializa la semilla de los numeros aleatorios
	do{
		jugar();
		cout << "desea jugar de nuevo (S|n) ";
		cin >> jugarDeNuevo;
		cout << endl;
	}while(toupper(jugarDeNuevo) == 'S');
	return 0;
}
 void jugar (){
 	char tablero[LADO][LADO] = {};
 	char ganador =0;
 	cout << " Juego de equis-cero" << endl;
 	int casillasLibres = LADO * LADO;
 	bool turnoJugador = true;
 	imprimirTablero(tablero);
 	
 	while (casillasLibres > 0 && ganador == 0){
 		if (turnoJugador){
 			casillasLibres -= marcarCasillaCompuradora(tablero); 			
		 }else{
 			casillasLibres  -= marcarCasillaCompuradora(tablero);
			}
		turnoJugador = !turnoJugador; // Turno del otro jugador
		ganador = determinarGanador(tablero);
	 }
	 switch (ganador){
	 	case 'X':
	 		cout << "usted gana!!!" << endl;
	 		break;
		case '0':
			cout << "la computadora gana :( " << endl;
			break;
		default:
			cout << "Empate. " << endl;
	 }
 }
 void imprimirTablero(char tablero[][LADO]){
 	//cuente los espacios usando los puntos
 	cout << "\n     0   1   2\n    -----------" << endl;
 	for (int fila = 0; fila < LADO; fila++){
 		cout << " " << fila << " |";
 		for (int columna = 0 ; columna < LADO; columna++){
 			cout << " " << tablero[fila][columna] << " |";
		 }
		cout << "\n   -----------" << endl;
	 }
	 cout << endl;
 }
 
 int leerNumero(string indicacion, string mensajeError, int min, int max){
 	int numero;
 	cout << indicacion << ": ";
 	//valida que la entrada sea entero
 	while(!(cin >> numero) || (numero < min || numero >= max) ){
 		cin.clear();
 		cin.ignore(10000, '\n');
 		cout << mensajeError << endl;
 		cout << indicacion << ": ";
	 }
	 return numero;
 }
 
 int marcarCasillaJugador(char tablero[][LADO]){
 	int fila, columna;
 	cout << "Jugador:" << endl;
 	string mensaje = "ingrese un valor entre 0 y " + to_string(LADO);
 	fila = leerNumero("fila", mensaje,0,LADO);
 	columna = leerNumero("columna", mensaje,0,LADO);
 	while(tablero[fila][columna] != 0){
 		cout << "casilla ocupada. Intente de nuevo" << endl;
 		fila = leerNumero("fila", mensaje,0,LADO);
 		columna = leerNumero("columna", mensaje,0,LADO);
	 }
	 tablero[fila][columna] = 'X';
	 imprimirTablero(tablero);
	 return 1;
 }
 
 int marcarCasillaCompuradora(char tablero[][LADO]){
 	int fila, columna;
 	fila = rand() % LADO;
 	columna = rand() % LADO;
 	while(tablero[fila][columna] != 0){
	 fila = rand() % LADO;
	 columna = rand() % LADO;
	 }
	 tablero[fila][columna] = '0';
	 cout << "computadora" << endl;
	 imprimirTablero(tablero);
	 return 1;
	 
 }
 
 char determinarGanador(char tablero[][LADO]){
 	char ganador;
 	ganador = ganadorFilas(tablero);
 	if (ganador == 0)
 		ganador = ganadorColumnas(tablero);
 	if (ganador == 0)
	 	ganador = ganadorDiagonales(tablero); 
		 return ganador;	
 }
 
char  ganadorFilas(char tablero[][LADO]){
	for (int fila =0; fila < LADO; fila++){
		char caracter = tablero[fila][0];
		int veces = 0;
		if (caracter != 0 ){
			for(int columna = 0; columna < LADO; columna++){
				if(tablero[fila][columna] == caracter){
					veces++;
				}
			}
			if(veces = LADO){
				return caracter;
			}
		}
	}
	return 0;
}

char  ganadorColumnas(char tablero[][LADO]){
	for (int columna =0; columna < LADO; columna++){
		char caracter = tablero[0][columna];
		int veces = 0;
		if (caracter != 0 ){
			for(int fila = 0; columna < LADO; fila++){
				if(tablero[fila][columna] == caracter){
					veces++;
				}
			}
			if(veces = LADO){
				return caracter;
			}
		}
	}
	return 0;
}

char ganadorDiagonales(char tablero[][LADO]){
	char caracter;
	int veces;
	caracter = tablero [0][0];
	veces = 0;
	if ( caracter != 0){
		for(int i = 0; i< LADO; i++)
			if(tablero[i][i] == caracter)
				veces++;
		if (veces == LADO)
		 return caracter;
	}
	caracter = tablero[0][LADO - 1];
	veces =0;
	if (caracter != 0){
		for (int i = 0; i < LADO; i++)
			if (tablero[i][LADO - 1 - i] == caracter)
				veces++;
		if (veces == LADO)
			return caracter;
	}
	return 0;
}
