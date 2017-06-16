#include "Administrador.h"

Administrador::Administrador(string usuario, string password, string cargo,int num_seguro):Usuario(usuario,password){
	this->cargo=cargo;
	this->num_seguro=num_seguro;
}
Administrador::Administrador(){

}void Administrador::setCargo(string cargo){
   this-> cargo=cargo;
}
string Administrador::getCargo(){
   return cargo;
}
void Administrador::setNum_seguro(int num_seguro){
   this-> num_seguro=num_seguro;
}
int Administrador::getNum_seguro(){
   return num_seguro;
}
void Administrador::metodo(){
	
}
