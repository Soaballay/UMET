// Cargar y mostrar datos de pc usando herencia de dos clases

#include<iostream.h>
#include<string.h>

class monitor_computadora {
	public:
	monitor_computadora(char *, long, int, int);
	void ver_monitor(void);
	
	private:
	char pantalla[32];
	long colores;
	int resolucion_x;
	int resolucion_y;
};

class tarjeta_madre {
	public:
	tarjeta_madre(int, int, int);
	void ver_tarjeta_madre (void);

	private:
	int procesador;
	int velocidad;
	int ram;
};

class computadora : public monitor_computadora, public tarjeta_madre{
	public:
	computadora(char *, int, float, char *, long, int, int, int, int, int);
	void ver_computadora(void);

	private:
	char nombre[64];
	int disco_duro;
	float floppy;
};

monitor_computadora::monitor_computadora(char *pantalla, long colores, int res_x, int res_y){
	strcpy(monitor_computadora::pantalla,pantalla);
	monitor_computadora::colores=colores;
	monitor_computadora::resolucion_x=res_x;
	monitor_computadora::resolucion_y=res_y;
}

tarjeta_madre::tarjeta_madre(int procesador, int velocidad, int ram){
	tarjeta_madre::procesador=procesador;
	tarjeta_madre::velocidad=velocidad;
	tarjeta_madre::ram=ram;
}

computadora::computadora(char *nombre, int disco_duro, float floppy,
char *pantalla, long colores, int res_x, int res_y, int procesador,
int velocidad, int ram): monitor_computadora(pantalla, colores, res_x, res_y),
tarjeta_madre(procesador, velocidad, ram){
	strcpy(computadora::nombre, nombre);
	computadora::disco_duro=disco_duro;
	computadora::floppy=floppy;
}

void monitor_computadora::ver_monitor(void){
	cout<<"Monitor Tipo: "<<pantalla<<endl;
	cout<<"Colores: "<<colores<<endl;
	cout<<"Resolucion: "<<resolucion_x<<" por "<<resolucion_y<<endl<<endl;
}

void tarjeta_madre::ver_tarjeta_madre(void){
	cout<<"Procesador: "<<procesador<<endl;
	cout<<"Velocidad: "<<velocidad<<endl;
	cout<<"Memoria RAM: "<<ram<<endl<<endl;
}

void computadora::ver_computadora(void){
	cout<<"Tipo: "<<nombre<<endl;
	cout<<"Disco Duro: "<<disco_duro<<endl;
	cout<<"Unidad Floppy: "<<floppy<<endl<<endl;
	ver_tarjeta_madre();
	ver_monitor();
}

void main(){
	computadora pc("Compaq", 212, 1.44, "SVGA", 16000000, 640, 480, 486, 66, 8);
	pc.ver_computadora();
}