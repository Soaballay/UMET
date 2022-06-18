#include <iostream.h>
#include <string.h>
#include <fstream.h>
#include <conio.h>

float costo_de;

struct estructura {
    public:
	    char string_1[10];      //codigo pieza
	    char string_2[64];      //descripcion
	    int miembro_1;          //cant fabricadas
	    int miembro_2;          //defectiosas
	    float miembro_3;        //costo unidad
};

void mostrar_estructura(estructura variable){
    if( variable.miembro_2 != 0)
        costo_de=costo_de + (variable.miembro_2 * variable.miembro_3);

    cout<<"\n DATOS INGRESADOS"<<endl;
    cout<<"Codigo pieza:  "<<variable.string_1<<endl;
    cout<<"descripcion:  "<<variable.string_2<<endl;
    cout<<"cant fabricadas:      "<<variable.miembro_1<<endl;
    cout<<"Defectuosas:   "<<variable.miembro_2<<endl;
    cout<<"Costo unidad: "<<variable.miembro_3<<endl;
}

void main(){
    estructura variable;
    ifstream archivo_emp("fabrica.dat");

    while((!archivo_emp.eof()) && (archivo_emp.read((char *) &variable, sizeof(estructura))))
	    mostrar_estructura(variable);

    cout<<"\n UNIDADES DEFECTUOSAS POR SU COSTO EN TOTAL"<<endl;
    cout<<"Costo defectuosas: "<<costo_de<<endl;
}