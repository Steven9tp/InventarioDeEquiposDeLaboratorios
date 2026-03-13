#include <iostream>
#include <string>

using namespace std;

// Estructura de cada vagon
struct Vagon {
    string nombre;      // Lo que lleva el vagon
    Vagon* siguiente;   // El enlace al siguiente vagon
};

// Clase para manejar el tren
class Tren {
private:
    Vagon* primero; // Es la locomotora (el inicio)
    int total;      // Para llevar la cuenta de cuantos hay

public:
    // Al principio el tren esta vacio
    Tren() {
        primero = NULL;
        total = 0;
    }

    // --- METODO INSERTAR ---
    void insertar(string valor) {
        Vagon* nuevo = new Vagon();
        nuevo->nombre = valor;
        nuevo->siguiente = NULL;

        if (primero == NULL) {
            // Si no hay nada, este es el primero
            primero = nuevo;
        } else {
            // Si ya hay vagones, buscamos el ultimo para engancharlo
            Vagon* temporal = primero;
            while (temporal->siguiente != NULL) {
                temporal = temporal->siguiente;
            }
            temporal->siguiente = nuevo;
        }
        total++;
        cout << "-> Vagon " << valor << " enganchado." << endl;
    }

    // --- METODO MOSTRAR ---
    void mostrar() {
        if (primero == NULL) {
            cout << "El tren no tiene vagones aun." << endl;
            return;
        }
        
        Vagon* temporal = primero;
        cout << "\nESTADO DEL TREN: ";
        while (temporal != NULL) {
            cout << "[" << temporal->nombre << "] === ";
            temporal = temporal->siguiente;
        }
        cout << "FIN" << endl;
    }

    // --- METODO BUSCAR ---
    void buscar(string queBusco) {
        Vagon* temporal = primero;
        int posicion = 1;
        
        while (temporal != NULL) {
            if (temporal->nombre == queBusco) {
                cout << "Encontrado: " << queBusco << " esta en el vagon numero " << posicion << endl;
                return;
            }
            temporal = temporal->siguiente;
            posicion++;
        }
        cout << "No se encontro el vagon: " << queBusco << endl;
    }

    // --- METODO ELIMINAR ---
    void eliminar(string aQuitar) {
        if (primero == NULL) return;

        Vagon* actual = primero;
        Vagon* anterior = NULL;

        // Buscamos el vagon que queremos quitar
        while (actual != NULL && actual->nombre != aQuitar) {
            anterior = actual;
            actual = actual->siguiente;
        }

        // Si no existe lo que pidio el usuario
        if (actual == NULL) {
            cout << "No existe ese vagon para eliminar." << endl;
            return;
        }

        // Si es el primero de la lista
        if (anterior == NULL) {
            primero = primero->siguiente;
        } else {
            // Reenganchamos el anterior con el que seguia
            anterior->siguiente = actual->siguiente;
        }

        delete actual; // Borramos el objeto de la memoria
        total--;
        cout << "Vagon " << aQuitar << " eliminado." << endl;
    }

    // --- METODO SIZE ---
    int size() {
        return total;
    }
};

int main() {
    Tren miTren;

    // Agregamos unos vagones de prueba
    miTren.insertar("Carbon");
    miTren.insertar("Maquinaria");
    miTren.insertar("Pasajeros");
    miTren.insertar("Cisterna");

    miTren.mostrar();
    
    cout << "\nCantidad de vagones: " << miTren.size() << endl;

    miTren.buscar("Pasajeros");

    miTren.eliminar("Maquinaria");
    miTren.mostrar();

    cout << "\nTotal al final: " << miTren.size() << endl;

    return 0;
}
