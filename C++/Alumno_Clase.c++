//EJERCICIOS TIPO PARCIAL CON CLASES

#include <iostream.h>
#include <fstream.h>

class umet {
public:
	umet(char *);
	void descarga(void);
private:
	char nombre[64];
	int matricula;
	int materias_aprobadas;
	float promedio;
};


umet::umet(char *name){
	cout<<"\t\tINGRESO DE DATOS"<<endl<<endl;
	cout<<"Ingrese Apellido y Nombre: ";
	cin.getline(umet::nombre,64);
	cout<<"Ingrese su matricula: ";
	cin>>umet::matricula;
	cout<<"Ingrese cantidad de materias aprobadas: ";
	cin>>umet::materias_aprobadas;
	cout<<"Ingrese su promedio: ";
	cin>>umet::promedio;
}

void umet::descarga(void){
	cout<<endl<<"\t\tDATOS INGRESADOS"<<endl<<endl;
	cout<<"Alumno:\t\t\t"<<nombre<<endl;
	cout<<"Matricula:\t\t"<<matricula<<endl;
	cout<<"Materias aprobadas:\t"<<materias_aprobadas<<endl;
	cout<<"Promedio:\t\t"<<promedio<<endl<<endl;
}

void main(){
	umet alumno("umet");
	alumno.descarga();
}
