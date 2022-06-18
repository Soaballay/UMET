//Cargar empleados usando estructura

#include <iostream.h>
#include <string.h>
#include <fstream.h>
#include <conio.h>

struct empleados {
public:
	char nombre[64];
	char area[15];
	long id_empleado;
   	float salario;
  	int no_oficina;
};

char temporal[2]="\0";

void carga(empleados trabajador){
	cin.getline(temporal,2);
	cout<<"\nIngrese Apellido y Nombre: ";
	cin.getline(trabajador.nombre,64);
	cout<<"Ingrese Area de trabajo: ";
	cin.getline(trabajador.area,15);
	cout<<"Ingrese el numero de legajo: ";
	cin>>trabajador.id_empleado;
	cout<<"Ingrese sueldo asignado: ";
	cin>>trabajador.salario;
	cout<<"Ingrese el numero oficina: ";
	cin>>trabajador.no_oficina;

	ofstream archivo_emp("emplea.txt", ios::app );
	archivo_emp.write((char *)&trabajador, sizeof(empleados));
	archivo_emp.close();
}

void main(){
	empleados trabajador;
	int canti;
	cout<<"Ingrese la cantidad de trabajadores a procesar:";
	cin>>canti;

	for(int i=0; i<canti; i++)
		carga(trabajador);
}
