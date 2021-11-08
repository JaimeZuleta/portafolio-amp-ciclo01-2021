#include <iostream>
#include <stdio.h>

using namespace std;

class Persona{
    public:
        Persona();
        void nombreCompleto();
        int edad();

    private:
        string nombres;
        string apellidos;
        int anioNacimiento;
};
Persona::Persona(){
    nombres="";
    apellidos="";
    anioNacimiento = 0;
}

void Persona::nombreCompleto(){
    string nombre1, nombre2, apellido1, apellido2;
    std::cout << "Digite su primer nombre: "<< std::endl;
    std::cin >> nombre1;
    std::cout << "Digite su segundo nombre: "<< std::endl;
    std::cin >> nombre2;
    std::cout << "Digite su primer apellido: "<< std::endl;
    std::cin >> apellido1;
    std::cout << "Digite su segundo apellido: "<< std::endl;
    std::cin >> apellido2;
    this->nombres = nombre1 + " " + nombre2;
    this->apellidos= apellido1 + " " + apellido2;
    std::cout << "\nNombre Completo: " << nombres << " " << apellidos <<std::endl;
}
int Persona::edad(){
    int edad=0;
    std::cout << "\nDigite su anio de nacimiento: "<< std::endl;
    std::cin >> this->anioNacimiento;
    edad= 2021 - anioNacimiento;
    std::cout << "\nSu edad es: " << edad << " anios." << std::endl;
}

int main(){
	bool bandera = true;
	int bandera2 = 0;
		while(bandera = true){
			Persona miPersona;
		    miPersona.nombreCompleto();
		    miPersona.edad();
		    std::cout << "\nDesea realizar otra operacion?" << std::endl;
				std::cout << "1. Si" << std::endl;
				std::cout << "2. No" << std::endl;
				std::cin >> bandera2;
				if(bandera2 ==  1){
					system("cls");
					bandera = true;
				}else{
					bandera = false;
					exit(0);
				}
		}
    return 0;
}
