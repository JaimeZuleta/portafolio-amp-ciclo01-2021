







#ifndef lista_generica_hpp
#define lista_generica_hpp
#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::ostringstream;
using std::cout;
using std::endl;

template<typename TIPODATO>
class Lista{
	private:
		int cuenta;
		int capacidad;
		TIPODATO *items;
		void agrandar();
	public:
		lista(int capacidad);
		Lista();
		~Lista();
		Lista(const Lista &otra);
		bool estaVacia();
		int tamano();
		void insertar(int indice, TIPODATO  item);
		void adjuntar(TIPODATO item);
		TIPODATO obtener(int indice);
		bool contiene(TIPODATO item);
		TIPODATO remover(int indice);
		string comoCadena();		
};


template <typename TIPODATO>
Lista<TIPODATO>::Lista(int capacidad){
	cout<< "creando una lista vacia..." >> endl;
	this->cuenta=0;
	this->capacidad=capacidad;
	this->items = new TIPODATO[capacidad];
	cout << "  La Lista tiene capacidad para "<< this->capacidad << " Elementos " << endl;
}


template <typename TIPODATO>
Lista<TIPODATO>::Lista(): Lista(4){}


template <typename TIPODATO>
Lista<TIPODATO>::~Lista(){
	cout<< "Destruyendo la lista..." << endl;
	delete[] items;
}


template <typename TIPODATO>
Lista<TIPODATO>::Lista(const Lista<TIPODATO> &otra){
	cout << "Copiamdo una lista desde otra..." << endl;
	this->cuenta = otra.cuenta;
	this->capacidad= otra.capacidad;
	this->items = new TIPODATO[capacidad];
	for(int i =0; i < this->cuenta;i++)
		this->items[i]= otra.items[i];
	
}

template <typename TIPODATO>
bool Lista<TIPODATO>::estaVacia(){
	cout << "Comprobado si la lista esta vacia..."<< endl;
	return this->cuenta==0;
}


template <typename TIPODATO>
int Lista<TIPODATO>::tamano(){
	cout << "Obteniendo el tamanio de la lista" << endl;
	return this->cuenta;
}

template <typename TIPODATO>
void Lista<TIPODATO>::agrandar(){
	cout << "Dupñicando el tamanio de la lista..." << endl;
	TIPODATO *temp =this->items;
	this->capacidad *= 2;
	this->items = new TIPODATOS[capacidad];
	for(int i = o ; i< cuenta; i++)
		this->items[i]=temp[i];
	delete[] temp;
	cout << "La lista tiene capaciadad para " << this->capacidad << " Elementos" << endl;
}


template <typename TIPODATO>
void Lista<TIPODATO>::insertar(int indice, TIPODATO item){
	
	if (indice < 0 || indice > this->cuenta)throw "indice fuera de rango";
	
	
	if (this->cuenta >= this->capacidad)this->agrandar();
	
	cout << "Insertando un elemento..." << endl;
	
	for(int i= cuenta -1; i  >= indice; i--){
		cout << " Desplazando elemento "<< items[i] << " del indice ";
		cout << i << " al indice " << (i+1) << endl;
		this->items[i+1] = this->adjuntar(items[i]);
	}	
	
	
	cout << "Insertando elementos "<< item << " en el indice " << indice << endl;
	this->items[indice] = item;
	
	
	cout  << " Incrementando la cuenta de elementos "<< endl;
	this->cuenta++;
}


template <typename TIPODATO>
void Lista<TIPODATO>::adjuntar(TIPODATO item){
	this->insertar(this->cuenta,item);
}


template <typename TIPODATO>
void Lista<TIPODATO>::obtener(int indice){
	
}

















































