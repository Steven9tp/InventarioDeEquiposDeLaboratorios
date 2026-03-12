#include <iostream> 
using namespace std;

class Equipo {

public:

	string nombre;
	string codigo;
	string estado;

	virtual void mostrarReporte() {
	
	cout << "Cod: " << codigo << " | Equipo: " << nombre << " | Estado: " << estado << endl; }

};

class Balanza : public Equipo {

public:

	void mostrarReporte() {
	
	cout << "[Balanza]     Cod: " << codigo << " | " << nombre << " (" << estado << ")" << endl; }

};

class Microscopio : public Equipo {

public:

	void mostrarReporte() {
	
	cout << "[Microscopio] Cod: " << codigo << " | " << nombre << " (" << estado << ")" << endl; }

};

     



int main() {

	
	Equipo* inventario[3];
	
	Balanza b1;
	b1.nombre = "Analitica";
	b1.codigo = "B01";
	b1.estado = "Calibrada";
	
	Microscopio m1;
	m1.nombre = "Binocular";
	m1.codigo = "M01";
	m1.estado = "Nuevo";
	
	Balanza b2;
	b2.nombre = "Digital";
	b2.codigo = "B02";
	b2.estado = "Usada";

	inventario[0] = &b1;
	inventario[1] = &m1;
	inventario[2] = &b2;

	int opcion;
	cout << "1. Ver Inventario Completo" << endl;
	cout << "2. Buscar Producto (Nombre o Codigo)" << endl;
	cout << "Seleccione una opcion: ";
	cin >> opcion;

	if (opcion == 1) {
	
		cout << "###### LISTADO TOTAL ######" << endl;
		for (int i = 0; i < 3; i++) {
			inventario[i]->mostrarReporte();
		}
		
	} else if (opcion == 2) {
	
		string busqueda;
		cout << "Ingrese el Nombre o Codigo a buscar: ";
		cin >> busqueda;
		
		bool encontrado = false;
		for (int i = 0; i < 3; i++) {
			// Busqueda doble: por nombre O por codigo
			if (inventario[i]->nombre == busqueda || inventario[i]->codigo == busqueda) {
				cout << "###### PRODUCTO ENCONTRADO ######" << endl;
				inventario[i]->mostrarReporte();
				encontrado = true;
			}
		}
		
		if (!encontrado) {
			cout << "###### Error: No se encontro ningun equipo con ese dato. ######" << endl;
		}
	}

	return 0;

}
