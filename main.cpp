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

//vector<Carro*> cargarTXT(vector<Carro*>);

int main(){

      Usuario* user;
      user=new Administrador("Josue", "Zelaya", "Polo", 22);

      vector<Usuario*> usuarios;
      usuarios.push_back(user);
      vector<Carro*> carros;
      //carros=cargarTXT(carros);
      bool libre=false;

      while (!libre){
        int opcion;
        cout<<"[1]. Registrarse"<<endl
        <<"[2]. Login"<<endl
        <<"[3]. Listar"<<endl
        <<"[4]. Salir"<<endl;
        cout<<"Ingrese opcion: "<<endl;

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
                if (dynamic_cast<Administrador*>(usuarios[i])){
                  cout<<"Administrador"<<endl;
                  bool fue=false;
                  while (!fue){
                    cout<<"[1]. Agregar"<<endl;
                    cout<<"[2]. Modificar"<<endl;
                    cout<<"[3]. Eliminar"<<endl;
                    cout<<"[4]. Listar Carros"<<endl;
                    cout<<"[5]. Salir"<<endl;
                    cout<<"Ingrese opcion"<<endl;
                    int opt=0;
                    string marca, modelo;
                    int year;
                    double precio;
                    if (opt==1){
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
                    }else if (opt==2){
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
                    }else if (opt==3){
                      int pos;
                      cout<<"Ingrese posicion a eliminar"<<endl;
                      cin>>pos;
                      carros.erase(carros.begin()+pos);
                    }else if (opt==4){
                      for (int i = 0; i < carros.size(); i++) {
                          cout<<" [ " <<i<<" ] ";
                         cout<<" Marca: "<<carros[i]->getMarca()<< " Modelo:  "
                         <<carros[i]->getModelo()<<cout<<" Año "<<
                         carros[i]->getYear()<<cout<<" Precio: "<<carros[i]->getPrecio()<<
                         cout<< " Placa "<<carros[i]->getPlaca()<<endl;
                      }
                    }else if (opt==5){
                      fue=true;
                    }
                  }

                }else if (dynamic_cast<Cliente*>(usuarios[i])){
                  bool seva=false;

                  while (!seva){
                    cout<<"Cliente"<<endl;
                    cout<<"Que desea hacer: "<<endl;
                    cout<<"[1]. Alquilar"<<endl
                    <<"[2]. Factura"<<endl
                    <<"[3]. Listar"<<endl
                    <<"[4]. Salir"<<endl;
                    cout<<"Ingrese opcion : "<<endl;
                    int op;
                    cin>>op;

                    switch (op) {
                      case 1:{//alquilar
                        cout<<"Ingrese posicion del carro que quiere alquilar: "<<endl;
                        int pos;
                        cin>>pos;
                        carros[pos]->setEstado("Alquilado");


                        break;
                      }
                      case 2:{//factura
                        /*ofstream archivo;
                        archivo.open("Factura.txt", ios::app);//abrimos el archivo en modo añadir
                        if (archivo.fail()){
                          cout<<"No se pudo abrir el archivo";
                          exit(1);
                        }
                        //archivo<<carros[pos].get<<endl;*/
                        break;
                      }
                      case 3:{
                        for (int i = 0; i < carros.size(); i++) {
                            cout<<" [ " <<i<<" ] ";
                           cout<<" Marca: "<<carros[i]->getMarca()<< " Modelo:  "
                           <<carros[i]->getModelo()<<cout<<" Año "<<
                           carros[i]->getYear()<<cout<<" Precio: "<<carros[i]->getPrecio()<<
                           cout<< " Placa "<<carros[i]->getPlaca()<<endl;
                        }
                        break;
                      }
                      case 4:{
                        seva=true;
                        break;
                      }
                    }

                  }

                }



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
          }

        }//fin switch
        return 0;
      }






/*vector<Carro*> cargarTXT(vector<Carro*> carros){


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
    archivo.close();
	}

	return carros;
}*/
