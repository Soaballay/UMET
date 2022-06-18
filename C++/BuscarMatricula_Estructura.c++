//Buscar matricula en archivo generado con estructura

#include <iostream.h>
#include <string.h>
#include <fstream.h>
#include <conio.h>

struct estructura {
public:
	char string_1[64];
	char string_2[32];
	char string_3[64];
	int miembro_1;
};

void mostrar_estructura(estructura variable){
	int matr;
	cout<<"Ingrese el numero de matricula a buscar:";
	cin>>matr;

	if(variable.miembro_1==matr) cout<<"La matricula se encuentra registrada"<<endl;
	else cout<<"La matricula no se encuentra registada"<<endl;
}

void main(){
	estructura variable;
	ifstream archivo_emp("alumnos.dat");

	if(archivo_emp.fail())
		cerr<<"Error al abrir archivo."<<endl;
	else {
		while((!archivo_emp.eof()) && (archivo_emp.read((char *) &variable, sizeof(estructura))))
		mostrar_estructura(variable);
	}
}
