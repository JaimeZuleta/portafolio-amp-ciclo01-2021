#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

void triangulo(){
	system("cls");
	float a,b,c,area,s;
	cout << " Clasificacion de tringulo por sus lados \n";
	cout << " Ingrese el primer lado: \n ";
	cin >> a;
	cout << " Ingrese el segundo lado: \n ";
	cin >> b;
	cout << " Ingrese el tercer lado: \n ";
	cin >> c;
	if (a == b && b == c){
		cout<< " El triangulo es Equilatero";
		area= (sqrt(3)/4)*( pow(a,2));
		cout<< "\n El area del triangulo es: " << area;
	}else{
		if(a == b || a == c || b == c){
			cout<< " El triangulo es Isoceles";
			if(a == c){
				area= (b*(sqrt(pow(a,2)-(pow(b,2)/4))))/(2);
				cout<< "\n El area del triangulo es: " << area;
			}else{
				if(a == b){
					area= (c*(sqrt(pow(a,2)-(pow(c,2)/4))))/(2);
					cout<< "\n El area del triangulo es: " << area;
				}else{
					area= (a*(sqrt(pow(b,2)-(pow(a,2)/4))))/(2);
					cout<< "\n El area del triangulo es: " << area;
				}
			}
		}else{
			if (a != b && a != c && c != b){
				cout<< " El triangulo es Escaleno";
				s= (a+b+c)/2;
				area= sqrt(s*(s-a)*(s-b)*(s-c));
				cout<< "\n El area del triangulo es: " << area;
				
			}
		}
	}
}

numero_mayor(){
	system("cls");	
	int a, b, c, d, e, mayor;
	cout << " 2. Numero mayor de una serie de 5 numeros \n";
	cout << "\n Ingrese numero 1: \n ";
	cin >> a;
	cout << "\n Ingrese numero 2: \n ";
	cin >> b;
	cout << "\n Ingrese numero 3: \n ";
	cin >> c;
	cout << "\n Ingrese numero 4: \n ";
	cin >> d;
	cout << "\n Ingrese numero 5: \n ";
	cin >> e;
	if( a > b){
		mayor = a;
	}else{
		mayor = b;
		}
	if(c > mayor)
	 mayor=c;
	 if( d > mayor)
	 mayor = d;
	 if( e > mayor)
	 mayor = e; 	 
	 cout << "\n El  numero mayor es: "<<mayor;
}
promedio(){
	system("cls");		
	cout << " 3. Promedio de una cantidad N de numeros\n ";
	float numeros, suma=0, cantidad, promedio;
	int i;
	cout << "Ingrese cantidad de numeros que desea calcular\n ";
	cin >> numeros;
	for(i=1;i<=numeros;i++)	{
		cout << " Ingrese el " << i << "° numero:\n ";
		cin >> cantidad;
		suma = suma + cantidad;
	}
	promedio = suma / numeros;
	cout << " El promedio es: " << promedio;
}

int main(){
	int op;
	cout << "\n Autor: \tJaime Esau Zuleta Calzada \n";
	cout << " Carnet: \tZC100417 \n\n";
	cout << " Seleccione una opcion: \n";
	cout << " 1. Clasificacion de tringulo por sus lados \n";
	cout << " 2. Numero mayor de una serie de 5 numeros \n";
	cout << " 3. Promedio de una cantidad N de numeros \n";
	cout << " 4. Salir \n ";
	cin >> op;
	switch (op){
		case 1: 			
			triangulo();
			break;
		case 2:
			numero_mayor();
			break;
		case 3:
			promedio();
			break;
		case 4:
			return 0;
			break;
		default:
			
			cout << " Opcion no valida \n";
			break;
	}
	
}
