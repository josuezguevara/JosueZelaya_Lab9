#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <fstream>
#include "Usuario.h"
#include "Administrador.h"
#include "Carro.h"
#include "Cliente.h"


using namespace std;

vector<Carro*> cargarTXT(vector<Carro*>);

int main(){
      bool libre=false;
      Usuario* user;
      user=new Administrador("Josue", "Zelaya", "Polo",123);

      vector<Usuario*> usuarios;
      usuarios.push_back(user);
      vector<Carro*> carros;
      carros=cargarTXT(carros);

      while (!libre){
        cout<<"[1]. Registrarse"<<endl
        <<"[2]. Login"<<endl
        <<"[3]. Listar"<<endl
        <<"[4]. Salir"<<endl;
        cout<<"Ingrese opcion: "<<endl;
        int opcion;
        cin>>opcion;
        switch (opcion) {
          case 1:{//registrase
            cout<<"Como desea registrase?"<<endl
            <<"[1]. Administador"<<endl
            <<"[2]. Cliente"<<endl;
            cout<<"Ingrese opcion: "<<endl;
            int op;
            cin>>op;
            string username, password,cargo, membresia;
            int num;
            if (op==1){//Administador

              cout<<"Ingrese username: "<<endl;
              cin>>username;
              cout<<"Ingrese contraseña: "<<endl;
              cin>>password;
              cout<<"Ingrese cargo en la empresa: "<<endl;
              cin>>cargo;
              cout<<"Ingrese su número de seguro social: "<<endl;
              cin>>num;

              Usuario* admin=new Administrador(username,password,cargo,num);
              usuarios.push_back(admin);
              cout<<"Se ha registrado correctamente"<<endl;


            }else if (op==2){//Cliente
              cout<<"Ingrese username: "<<endl;
              cin>>username;
              cout<<"Ingrese contraseña: "<<endl;
              cin>>password;
              cout<<"Ingrese su membresia"<<endl;
              cin>>membresia;

              Usuario* cliente=new Cliente(username, password,membresia);
              usuarios.push_back(cliente);
              cout<<"Se ha registrado correctamente"<<endl;

            }else{
              cout<<"Opcion no valida"<<endl;
            }

            break;
          }
          case 2:{ //login
            string username,pass;

            cout<<"Ingrese username: "<<endl;
            cin>>username;
            cout<<"Ingrese contraseña: "<<endl;
            cin>>pass;
            for (int i = 0; i < usuarios.size(); i++) {
              cout<<"Entro 1"<<endl;
              if ((username==usuarios[i]->getUsuario()) && (pass==usuarios[i]->getPassword())){
                cout<<"Entro 2"<<endl;
                /*if (typeid(*usuarios[i])==typeid(Administrador)){
                  cout<<"Administrador"<<endl;
                }else if (dynamic_cast(*usuarios[i])==dynamic_cast(Cliente)){
                  cout<<"Cliente"<<endl;
                }*/
                if (dynamic_cast<Administrador*>(usuarios[i])){
                  cout<<"Administrador"<<endl;
                  bool libre=false;
                  while(!libre){
                    cout<<"[1]. Agregar"<<endl
                    <<"[2]. Modificar"<<endl
                    <<"[3]. Eliminar"<<endl
                    <<"[4]. Listar Carros"<<endl
                    <<"[5]. Salir"<<endl;
                    cout<<"Ingrese opcion"<<endl;
                    int opcion;
                    string marca, modelo;
                    int year;
                    double precio;
                    switch (opcion) {
                      case 1:{//agregar
                        cout<<"Ingrese Marca: "<<endl;
                        cin>>marca;
                        cout<<"Ingrese modelo: "<<endl;
                        cin>>modelo;
                        cout<<"Ingrese el año: "<<endl;
                        cin>>year;
                        cout<<"Ingrese el precio de alquiler"<<endl;
                        cin>>precio;
                        Carro* carro=new Carro(marca,modelo,year,precio,"Disponible");
                        carros.push_back(carro);
                        break;
                      }
                      case 2:{//modificar
                        int pos;
                        string estado;
                        cout<<"Ingrese posicion a modificar"<<endl;
                        cin>>pos;

                        cout<<"Ingrese Marca Nuevo: "<<endl;
                        cin>>marca;
                        cout<<"Ingrese modelo nueva: "<<endl;
                        cin>>modelo;
                        cout<<"Ingrese el año nuevo: "<<endl;
                        cin>>year;
                        cout<<"Ingrese el precio de alquiler nuevo"<<endl;
                        cin>>precio;
                        cout<<"Ingrese estado"<<endl;
                        cin>>estado;


                        carros[pos]->setMarca(marca);
                        carros[pos]->setModelo(marca);
                        carros[pos]->setYear(year);
                        carros[pos]->setPrecio(precio);
                        carros[pos]->setEstado(estado);
                        break;
                      }
                      case 3:{//eliminar
                        int pos;
                        cout<<"Ingrese posicion a eliminar"<<endl;
                        cin>>pos;
                        carros.erase(carros.begin()+pos);
                        break;
                      }
                      case 4:{//listar
                        for (int i = 0; i < carros.size(); i++) {
                            cout<<" [ " <<i<<" ] ";
                           cout<<" Marca: "<<carros[i]->getMarca()<< " Modelo:  "
                           <<carros[i]->getModelo()<<cout<<" Año "<<
                           carros[i]->getYear()<<cout<<" Precio: "<<carros[i]->getPrecio()<<
                           cout<< " Placa "<<carros[i]->getPlaca()<<endl;
                        }
                        break;
                      }
                      case 5:{
                        libre=true;
                        break;
                      }
                    }
                  }

                }else if (dynamic_cast<Cliente*>(usuarios[i])){
                  cout<<"Cliente"<<endl;
                }

                break;
              }else{
                cout<<"Usuario y Contraseña Incorrectos"<<endl;

              }
            }
            break;
          }
          case 3:{
            break;
          }
          case 4:{
              libre=true;
            break;
          }
        }//fin switch


      }

     return 0;
}

vector<Carro*> cargarTXT(vector<Carro*> carros){


	ifstream archivo;
  archivo.open("Reporte.txt", ios::in);


   	while(!archivo.eof()){


   		string marca;
      string modelo;
      double precio;
      int year;
      string estado;


   		archivo >> marca;
      archivo>>modelo;
      archivo>>precio;
      archivo>>year;
      archivo>>estado;

 		Carro* carro = new Carro(marca,modelo,precio,year,estado);
		carros.push_back(carro);
	}

	return carros;
}
