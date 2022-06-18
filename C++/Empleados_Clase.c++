//Cargar y mostrar empleados usando clases

#include <iostream.h>
#include <string.h>

class empleados{				//CLASE EMPLEADOS
	public:
	char nombre[64];
	long id_empleado;
	float salario;
	char telefono[10];
	int no_oficina;

	void cargar_estructura(void);    	//PROTOTIPOS 
	void mostrar_estructura(void);
};

void empleados::cargar_estructura(void){    // OPERADOR DE RESOLUCION GLOBAL
	cout<<"Ingrese su nombre: ";
	cin>>nombre;
	cout<<"Ingrese el numero de identificacion: ";
	cin>>id_empleado;
	cout<<"Ingrese su salario: ";
	cin>>salario;
	cout<<"Ingrese su telefono: ";
	cin>>telefono;
	cout<<"Ingrese el numero de oficina: ";
	cin>>no_oficina;
	cout<<endl;
}

void empleados::mostrar_estructura(void) {		
	cout<<"Empleado: "<<nombre<<endl;
	cout<<"ID Empleado: "<<id_empleado<<endl;
	cout<<"Salario: "<<salario<<endl;
	cout<<"Telefono: "<<telefono<<endl;
	cout<<"Oficina: "<<no_oficina<<endl<<endl;
}

void main(){
	empleados trabajador, jefe;          //SE DEFINE OBJETO TRABAJADOR Y JEFE
	trabajador.cargar_estructura();      
	jefe.cargar_estructura();

	trabajador.mostrar_estructura();
	jefe.mostrar_estructura();
}