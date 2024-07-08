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

void agregaContacto(contactoEmail arr[],int& n) {
	system("cls");
	cout<<"Ingrese el nombre de la persona: ";
	cin.ignore();
	getline(cin,arr[n].nombreCompleto);
	cout<<"Ingrese su sexo (M/F): ";
	cin>>arr[n].sexo;
	cout<<"Ingrese su edad: ";
	cin>>arr[n].edad;
	cout<<"Ingrese su nacionalidad: ";
	cin>>arr[n].nacionalidad;
    cout<<"Ingrese su email: ";
	cin>>arr[n].email;
	cout<<"Ingrese su numero de telefono: ";
	cin>>arr[n].telefono;
	cout<<"\nContacto Agregado\n"<<endl;
	n++;
	system("pause");
}

void eliminarContacto(contactoEmail arr[], int& n) {
	int indice;
	int contacto;
	system("cls");
	cout<<"Lista de Contactos:\n"<<endl;
		for (int j=0;j<n;j++) {
			cout<<"CONTACTO "<<j+1<<" :\n"<<endl;
			cout<<"Nombre: "<<arr[j].nombreCompleto<<endl<<endl;
		}
			cout<<"Digite el numero de contacto que desea eliminar: ";
			cin>>contacto;
			indice=contacto-1;
		if (indice >= 0 && indice < n) {
			for (int j=indice;j<n-1;++j) {
				arr[j]=arr[j+1];
			}
			n--;
			cout<<"\nContacto eliminado\n"<<endl;
		} else {
		cout<<"\nIndice no valido\n"<<endl;
		}
	system("pause");
}

void listaContacto(contactoEmail arr[], int n) {
	system("cls");
	cout<<"Listado general de contactos registrados:\n"<<endl;
	for (int i=0;i<n;i++) {
		cout<<"CONTACTO "<<i+1<<" :\n"<<endl;
		cout<<"Nombre: "<<arr[i].nombreCompleto<<endl;
		cout<<"Sexo: "<<arr[i].sexo<<endl;
		cout<<"Edad: "<<arr[i].edad<<endl;
		cout<<"Nacionalidad: "<<arr[i].nacionalidad<<endl;
		cout<<"Email: "<<arr[i].email<<endl;
		cout<<"Telefono: "<<arr[i].telefono<<endl<<endl;
	}
	system("pause");
}

void ordenEmail(contactoEmail arr[],contactoEmail arrCopia[], int& n) {
	//genera copia de la lista
	for (int i = 0; i < n; ++i) {
        arrCopia[i] = arr[i];
    }
		int tam[n];
		int i,j;
		contactoEmail aux;
		string dominio[n];
		string auxDom;
	//Determinar longitud de los arreglo y almacenar los dominios
	for (i=0;i<n;i++) {
    	tam[i] = (arrCopia[i].email).length(); //longitud caracteres
    	for (j=0;j<tam[i];j++) {
			if ((arrCopia[i].email)[j]=='@') {
				while ((arrCopia[i].email)[j]!='\0') {
					j++;
					dominio[i]+=(arrCopia[i].email)[j];
				}	
			}
		}
	}
	//Ordena por dominio de correo
	for (i=0;i<n-1;i++) {
		for (j=i+1;j<n;j++) {
			if (dominio[i]>dominio[j]) {
				aux=arrCopia[i];
				arrCopia[i]=arrCopia[j];
				arrCopia[j]=aux;
							
				auxDom=dominio[i];
				dominio[i]=dominio[j];
				dominio[j]=auxDom;
			}
		}
	}
	system("cls");
	for (i=0;i<n;i++) {
		cout<<"CONTACTO "<<i+1<<" :\n"<<endl;
		cout<<"Servidor: "<<dominio[i]<<endl<<endl;
		cout<<"Nombre: "<<arrCopia[i].nombreCompleto<<endl;
		cout<<"Nacionalidad: "<<arrCopia[i].nacionalidad<<endl;
		cout<<"Sexo: "<<arrCopia[i].sexo<<endl;
		cout<<"Edad: "<<arrCopia[i].edad<<endl;
		cout<<"Telefono: "<<arrCopia[i].telefono<<endl;
		cout<<"Email: "<<arrCopia[i].email<<endl<<endl;
	}
	system("pause");
}

int main() {
	const int MAX=1000; //Maximo numero de contactos
	contactoEmail ListadoContactos[MAX]={
		{"Pedro Manuel",'M',20,"934233321","pedroman@gmail.com","Peruana"},
		{"Amelia Rodriguez",'F',22,"967328325","ameliro@outlook.com","Chilena"},
		{"Luis Javier",'M',24,"992342547","luisjav@gmail.com","Peruana"},
		{"Juan Garcia",'M',26,"978324524","juangar@yahoo.com","Argentina"},
		{"Nicole Fernandez",'F',17,"954234256","nicolefe@outlook.com","Peruana"},
		{"Ricardo Diaz",'M',19,"912324573","ricardodi@yahoo.com","Boliviana"}
	};
	
	contactoEmail ListadoCopia[MAX];
	int op;
	int n=6; //numero de contactos inicial
	
	do {
		system("cls");
		cout<<"Menu de Gestion de Contactos:"<<endl;
		cout<<"1. Agregar un contacto"<<endl
			<<"2. Eliminar un contacto"<<endl
			<<"3. Mostrar listado general de contactos registrados hasta el momento"<<endl
			<<"4. Mostrar listado de contactos existentes ordenado por servidor de correo electronico"<<endl
			<<"5. Salir del programa"<<endl;
		cin>>op;
		switch (op) {
			case 1: //agregar un contacto
				agregaContacto(ListadoContactos,n);
				break;
			case 2: //eliminar un contacto
				eliminarContacto(ListadoContactos,n);
				break;
			case 3: //listado de contactos
				listaContacto(ListadoContactos,n);
				break;
			case 4: //ordenamiento por correo
				ordenEmail(ListadoContactos,ListadoCopia,n);
				break;
			case 5: //salir del programa
				cout<<"Saliendo del Programa"<<endl;
				break;
			default:
				cout<<"Ingrese una opcion valida\n"<<endl;
				system("pause");
		}
	} while (op!=5);
	return 0;
}