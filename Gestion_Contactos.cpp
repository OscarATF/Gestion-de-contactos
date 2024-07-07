#include <iostream>
#include <string.h>
using namespace std;
struct contactoEmail {
	string nombreCompleto;
	char sexo;
	int edad;
	string telefono;
	string email;
	string nacionalidad;
};

int main() {
	const int MAX=1000;
	contactoEmail ListadoContactos[MAX]={
		{"Pedro Manuel",'M',20,"934233321","pedroman@gmail.com","Peruana"},
		{"Amelia Rodriguez",'F',22,"967328325","ameliro@outlook.com","Chilena"},
		{"Luis Javier",'M',24,"992342547","luisjav@gmail.com","Peruana"},
		{"Juan Garcia",'M',26,"978324524","juangar@yahoo.com","Argentina"},
		{"Nicole Fernandez",'F',17,"954234256","nicolefe@outlook.com","Peruana"},
		{"Ricardo Diaz",'M',19,"912324573","ricardodi@yahoo.com","Boliviana"}
	};
	
	int op;
	int n=6;
	
	do {
		system("cls");
		cout<<"Menu de Gestion de Contactos:"<<endl;
		cout<<"1. Agregar un contacto"<<endl
			<<"2. Eliminar un contacto"<<endl
			<<"3. Mostrar listado general de contactos registrados"<<endl
			<<"4. Mostrar listado de contactos existentes"<<endl
			<<"5. Salir del programa"<<endl;
		cin>>op;
		switch (op) {
			case 1: //agregar un contacto
				break;
			case 2: //eliminar un contacto
				break;
			case 3: //listado de contactos
				break;
			case 4: //ordenamiento por correo
				break;
			case 5: //salir del programa
				cout<<"Saliendo del Programa"<<endl;
				break;
			default:
				cout<<"Ingrese una opcion valida"<<endl;
		}
	} while (op!=5);
	return 0;
}