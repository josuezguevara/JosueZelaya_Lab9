#include "Carro.h"

Carro::Carro(string marca, string modelo,double precio,int year, string estado){
	//placa=aleatorio();
	this->marca=marca;
	this->modelo=modelo;
	this->precio=precio;
	this->year=year;
	this->estado=estado;
}
Carro::Carro(){

}

/*string Carro::aleatorio(){
	static const char alphanum[] =
	"0123456789"
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char* letra=new char[1];

	int stringLength = sizeof(alphanum) - 1;
	for (int i = 0; i < 21; ++i) {
			letra[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
			if (letra[i]==

  }
	for (int i = 0; i < ; i++) {
		if ()
	}



}*/
void Carro::metodo(){

}
void Carro::setModelo(string modelo){
   this-> modelo=modelo;
}
string Carro::getModelo(){
   return modelo;
}

void Carro::setMarca(string marca){
   this-> marca=marca;
}
string Carro::getMarca(){
   return marca;
}

void Carro::setPlaca(string placa){
   this-> placa=placa;
}
string Carro::getPlaca(){
   return placa;
}

void Carro::setPrecio(double precio){
   this-> precio=precio;
}
double Carro::getPrecio(){
   return precio;
}
void Carro::setYear(int year){
   this-> year=year;
}
int Carro::getYear(){
   return year;
}
string Carro::getEstado(){
	return estado;
}

void Carro::setEstado(string estado){
	this->estado=estado;
}
