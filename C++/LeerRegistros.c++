//Lee varios registros de archivo generado

#include <iostream.h>
#include <string.h>
#include <fstream.h>
#include <conio.h>

struct estructura {
public:
	char string_1[64];    	//marca
	char string_2[10];         	//modelo
	long miembro_1;        	//precio
	float miembro_2;           	//stock
	//int miembro_3;
	};

void mostrar_estructura(estructura variable){
	cout<<"\n DATOS INGRESADOS"<<endl;
	cout<<"Marca:  "<<variable.string_1<<endl;
	cout<<"Modelo:       "<<variable.miembro_1<<endl;
	cout<<"Precio:   "<<variable.string_2<<endl;
	cout<<"Stock:   "<<variable.miembro_2<<endl;
}

void main(){
	estructura variable;
	ifstream archivo_emp("archivo.dat");

	while((!archivo_emp.eof()) && (archivo_emp.read((char *) &variable, sizeof(estructura))))
		mostrar_estructura(variable);
}
