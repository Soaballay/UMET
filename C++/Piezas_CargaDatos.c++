// Carga datos y graba archivo

#include <iostream.h>
#include <string.h>
#include <fstream.h>
#include <conio.h>

struct estructura {
    public:
	    char string_1[10];      //cod pieza
    	char string_2[64];      //descripcion
    	int miembro_1;          //cantidad fabricada
    	int miembro_2;          //cantidad defectuosas
    	float miembro_3;        //costo unidad
};

char temporal[2]="\0";          //limpia el buffer para poder ingresar otro registro

void carga(estructura variable){
    cin.getline(temporal,2);    //para q ande el getline limpia el bufer
    cout<<"Codigo de Pieza: ";
    cin.getline(variable.string_1,10);
    cout<<"Ingrese descripcion: ";
    cin.getline(variable.string_2,64);
    cout<<"Cantidad fabricadas: ";
    cin>>variable.miembro_1;
    cout<<"cantidad defectuosas: ";
    cin>>variable.miembro_2;
    cout<<"Ingrese costo de la unidad: ";
    cin>>variable.miembro_3;
    cout<<endl;
    ofstream archivo_emp("fabrica.dat", ios::app );
    archivo_emp.write((char *)&variable, sizeof(estructura));
}

void main(){
    estructura variable;
    int canti;
    cout<<"Ingrese la cantidad a procesar:";
    cin>>canti;

    for(int i=0; i<canti; i++)
	    carga(variable);
}
