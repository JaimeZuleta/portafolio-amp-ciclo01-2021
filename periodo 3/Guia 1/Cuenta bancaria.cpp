#include <iostream>
#include <stdio.h>

using namespace std;
class CuentaBancaria{
    public:
        CuentaBancaria();
        float get_saldo() const;
        void get_numeroCuenta() const;
        void get_NombreTitular() const;
        float depositar(float importeDeposito);
        float retirar(float ImporteRetiro);
        
    private:
        string numeroCuenta;
        string nombreTitular;
        double saldo;
};
CuentaBancaria::CuentaBancaria(){
    numeroCuenta="1234-1234-1234-1234";
    nombreTitular="Jaime Esu Zuleta Calzada";
    saldo = 5000.01;
}

float CuentaBancaria::get_saldo() const{
    return saldo;
}
void CuentaBancaria::get_NombreTitular() const{
    std::cout << "Nombre del titular: " << nombreTitular << std::endl;
}
void CuentaBancaria::get_numeroCuenta() const{
    std::cout << "Numero de cuenta: " << numeroCuenta << std::endl;
}
float CuentaBancaria::depositar(float importeDeposito){
   if(importeDeposito>0){
       saldo = saldo + importeDeposito;
       std::cout << "Importe del deposito: " << importeDeposito << endl;
       std::cout << "Nuevo saldo: $" << saldo << endl;
   }else{
        cout << "no puede depositar una cantidad negativa";
   }
}
float CuentaBancaria::retirar(float ImporteRetiro){
    if(ImporteRetiro <= saldo){
        saldo = saldo - ImporteRetiro;
        std::cout << "Importe del retiro: " << ImporteRetiro << endl;
        std::cout << "Nuevo saldo: $" << saldo << endl;
    }else{
        cout<< "El retiro no puede ser mayor al Saldo actual";
    }
    
}
int main(){
    bool bandera = false;
    int opc=0;
    int bandera2= 0;
    float deposito;
    float retiro;
    CuentaBancaria miCuenta;
    while(bandera = true){
		std::cout << "Que operacion desea realizar:";
		std::cout << "\n\t1. Depositar dinero";
		std::cout << "\n\t2. Retirar dinero";
		std::cout << "\n\t3. Salir"<<std::endl;
		std::cin >> opc;
		switch(opc){
			case 1:
				system("cls");
				miCuenta.get_NombreTitular();
				miCuenta.get_numeroCuenta();
				std::cout << "Saldo Actual: $" <<miCuenta.get_saldo() << std::endl ;
				cout << "Ingrese importe a depositar: "<< endl;
	    		std::cin >> deposito;
	    		miCuenta.depositar(deposito);  		
				std::cout << "\nDesea realizar otra operacion?" << std::endl;
				std::cout << "1. Si" << std::endl;
				std::cout << "2. No" << std::endl;
				std::cin >> bandera2;
				if(bandera2 == 1){
					system("cls");
					bandera =true;
				}else{
					bandera = false;
					exit(0);
					break;
				}
				break;	
			case 2:
				system("cls");
				miCuenta.get_NombreTitular();
				miCuenta.get_numeroCuenta();
				std::cout << "Saldo Actual: $" <<miCuenta.get_saldo() << std::endl ;
				cout << "Ingrese importe a retirar: "<< endl;
	    		std::cin >> retiro;
    			miCuenta.retirar(retiro);		
				std::cout << "\nDesea realizar otra operacion?" << std::endl;
				std::cout << "1. Si" << std::endl;
				std::cout << "2. No" << std::endl;
				std::cin >> bandera2;
				if(bandera2 == 1){
					system("cls");
					bandera =true;
				}else{
					bandera = false;
					exit(0);
					break;
				}
				break;
			case 3:
				exit(0);
				break;	
			default:
				system("cls");
				std::cout << "Debe ingresar una opcion valida" << std::endl;							
				break;				
		}	
	}    
    return 0; 
}
