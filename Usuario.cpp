#include "Usuario.h"

Usuario::Usuario(string usuario,string password){
	this->usuario=usuario;
	this->password=password;
}
Usuario::Usuario(){

}void Usuario::setUsuario(string usuario){
   this-> usuario=usuario;
}
string Usuario::getUsuario(){
   return usuario;
}
void Usuario::setPassword(string password){
   this-> password=password;
}
string Usuario::getPassword(){
   return password;
}
void Usuario::metodo(){
	
}
