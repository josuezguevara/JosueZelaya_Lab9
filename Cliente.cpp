#include "Cliente.h"

Cliente::Cliente(string usuario, string password, string membresia):Usuario(usuario,password ){
	this->membresia=membresia;
}
Cliente::Cliente(){

}void Cliente::setMembresia(string membresia){
   this-> membresia=membresia;
}
string Cliente::getMembresia(){
   return membresia;
}
