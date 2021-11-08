#include <stdlib.h>
#include <iostream>

using namespace std;
class Personaje{
    private:
        string nombre;
        int puntosVida;
    public:
        Personaje();
        int recibirGolpe(int puntosPerdidos);
        bool estaVivo();
        int getPuntosVida();//devuelve el atributo 
        string getNombre();//devuelve el atributo
        string setNombre();
        int comer(int puntosGanados);
};
Personaje::Personaje(){
    nombre="";
    puntosVida = 100;
}
string Personaje::setNombre(){
    string name;
    std::cout << "Ingrese el nombre de su personaje" << std::endl;
    std::cin >> name;
    this->nombre=name;
    return nombre;
}
string Personaje::getNombre(){
    return nombre;
}
int Personaje::getPuntosVida(){
    return puntosVida;
}
 bool Personaje:: estaVivo(){
     if(puntosVida<=0){
         return false;
     }
    return true;
 }
int Personaje::recibirGolpe(int puntosPerdidos){
    int vida;
    vida = this->puntosVida;
    this->puntosVida= vida-puntosPerdidos;
    return puntosVida;
}
int Personaje::comer(int puntosGanados){
    int vida;
    vida = this->puntosVida;
    if(vida>=100){
        this->puntosVida= 100;
    return puntosVida;
    }
    this->puntosVida= vida+puntosGanados;
    return puntosVida;
}
int main(){
    int opc;
    bool bandera = true;
    string estado;
    Personaje miPersonaje;
    miPersonaje.setNombre();
    while(bandera = true){
    	system("cls");
    if(miPersonaje.estaVivo()==true){
        estado ="Vivo";
    }else{
        estado ="Muerto";
    }
    std::cout << "Nombre del personaje:" << "\t| Puntos de vida:" << "\t| Estado:"<< std::endl;
    std::cout << miPersonaje.getNombre()<<"\t\t\t| "<<miPersonaje.getPuntosVida() <<"\t\t\t| "<<estado << std::endl;
    std::cout << "Que desea hacer" << std::endl;
    std::cout << "1. Recibir Golpe" << std::endl;
    std::cout << "2. Comer" << std::endl;
    std::cout << "3. Salir" << std::endl;
    std::cin >> opc;
    switch(opc){
        case 1:
            int golpe;
            std::cout << "Digite la cantidad de puntos que desea quitar" << std::endl;
            std::cin >> golpe;
            miPersonaje.recibirGolpe(golpe);
            bandera = true;
            break;
        case 2:
            if(miPersonaje.estaVivo()==true){
                int comer;
                std::cout << "Digite la cantidad de puntos que desea comer" << std::endl;
                std::cin >> comer;
                miPersonaje.comer(comer);
            }else{
                std::cout << "Su personaje esta muerto no lo puede revivir " << std::endl;
                std::cout << "Reinicie el programa " << std::endl;
                system("PAUSE");
            }
            bandera = true;
            break;
        case 3:
            exit(0);
            bandera = false;
            break;
        default:
        std::cout << "Opcion no valida" << std::endl;
        bandera = true;
        break;
    }
	}
    return 0;
}

