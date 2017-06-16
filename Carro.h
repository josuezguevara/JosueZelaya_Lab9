#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef CARRO_H
#define CARRO_H
class Carro{
	protected:
		string placa;
		string modelo;
		double precio;
		string estado;
		string marca;
		int year;
	public:
		Carro(string,string,double,int,string);
		Carro();
		string aleatorio();

		string getModelo();
		void setModelo(string);

		string getMarca();
		void setMarca(string);

		double getPrecio();
		void setPrecio(double);

		int getYear();
		void setYear(int);

		string getEstado();
		void setEstado(string);

		string getPlaca();
		void setPlaca(string);


		virtual void metodo();

};
#endif
