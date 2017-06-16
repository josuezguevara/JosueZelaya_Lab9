#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef USUARIO_H
#define USUARIO_H
class Usuario{
	protected:
		string usuario;
		string password;
	public:
		Usuario(string,string);
		Usuario();
		string getUsuario();
		void setUsuario(string);

		string getPassword();
		void setPassword(string);

		virtual void metodo();

};
#endif
