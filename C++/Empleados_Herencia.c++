//Cargar y mostrar empleados usando clases

#include <iostream.h>
#include <string.h>

class empleados{
	public:
	empleados (char*, char*, float);     //CONSTRUCTOR
	void ver_empleado(void);

	private:
	char nombre [64];
	char posicion [64];
	float salario;
};

empleados::empleados(char *nombre, char *posicion, float salario){
	strcpy(empleados::nombre, nombre);
	strcpy(empleados::posicion, posicion);
	empleados::salario=salario;
}

void empleados::ver_empleado(void){
	cout<<endl<<"Nombre: "<<nombre<<endl;
	cout<<"Posicion: "<<posicion<<endl;
	cout<<"Salario: "<<salario<<endl;
}

class gerentes:public empleados{		//HERENCIA DE CLASE EMPLEADOS
	public:
	gerentes (char*, char*, float, char*, float, int); 
	void ver_gerentes(void);
	private:
	char auto_empresa [64];
	float bono_anual;
	int opciones_acciones;
};

gerentes::gerentes(char *nombre, char *posicion, float salario, char *auto_empresa, float bono_anual, int opciones_acciones): empleados(nombre, posicion, salario){
	strcpy(gerentes::auto_empresa, auto_empresa);
	gerentes::bono_anual=bono_anual;
	gerentes::opciones_acciones=opciones_acciones;
}

void gerentes::ver_gerentes(void){
	ver_empleado();                              
	cout<<"Auto empresa: "<<auto_empresa<<endl;
	cout<<"Bono anual: "<<bono_anual<<endl;
	cout<<"Opciones acciones: "<<opciones_acciones<<endl;
}

void main (){
	empleados trabajador("Juan Lopez", "Operador", 15000.0);
	gerentes jefe("Marcelo Diaz", "Gerente", 400000.0, "Impala", 50000.0, 2);
	trabajador.ver_empleado();
	jefe.ver_gerentes();
}