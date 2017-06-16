#include "Usuario.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
class Administrador: public Usuario{
	protected:
		string cargo;
		int num_seguro;
	public:
		Administrador(string,string,string,int);
		Administrador();
		string getCargo();
		void setCargo(string);

		int getNum_seguro();
		void setNum_seguro(int);
		virtual void metodo();

};
#endif
