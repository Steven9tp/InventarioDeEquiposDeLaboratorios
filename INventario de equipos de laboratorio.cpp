#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- CLASE BASE (Herencia) ---
class Equipo {
public:
    string codigo;
    string nombre;
    string estado;

    // El destructor virtual es clave para no tener fugas de memoria
    virtual ~Equipo() {}

    // Funcion Virtual (Polimorfismo)
    virtual void mostrarInfo() {
        cout << "ID: " << codigo << " | Equipo: " << nombre << " | Estado: " << estado << endl;
    }
};

// --- CLASES HIJAS ---
class EquipoEspecializado : public Equipo {
public:
    void mostrarInfo() {
        cout << "[LAB] Cod: " << codigo << " | " << nombre << " (" << estado << ")" << endl;
    }
};

int main() {
    // Vector de punteros para permitir polimorfismo
    vector<Equipo*> inventario;

    // 1. CARGA DE 10 REGISTROS INICIALES
    string cods[] = {"E01", "E02", "E03", "E04", "E05", "E06", "E07", "E08", "E09", "E10"};
    string noms[] = {"Balanza", "Microscopio", "Centrifuga", "Autoclave", "Termometro", 
                     "Probeta", "Pipeta", "Agitador", "Estufa", "PH-Metro"};

    for (int i = 0; i < 10; i++) {
        EquipoEspecializado* nuevo = new EquipoEspecializado();
        nuevo->codigo = cods[i];
        nuevo->nombre = noms[i];
        nuevo->estado = "Operativo";
        inventario.push_back(nuevo);
    }

    int opcion;
    do {
        cout << "\n--- SISTEMA DE INVENTARIO (HERENCIA Y POLIMORFISMO) ---" << endl;
        cout << "1. Registrar Equipo" << endl;
        cout << "2. Mostrar Todos (Polimorfismo)" << endl;
        cout << "3. Buscar por Codigo" << endl;
        cout << "4. Modificar Registro" << endl;
        cout << "5. Eliminar Registro" << endl;
        cout << "6. Reporte Final" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione: ";
        cin >> opcion;

        if (opcion == 1) {
            EquipoEspecializado* nuevo = new EquipoEspecializado();
            cout << "Codigo: "; cin >> nuevo->codigo;
            cout << "Nombre: "; cin >> nuevo->nombre;
            cout << "Estado: "; cin >> nuevo->estado;
            inventario.push_back(nuevo);
            cout << "¡Registrado!" << endl;
        }

        else if (opcion == 2) {
            cout << "\n--- LISTA TOTAL ---" << endl;
            for (int i = 0; i < inventario.size(); i++) {
                // Aqui se aplica polimorfismo: llama a la funcion de la clase hija
                inventario[i]->mostrarInfo();
            }
        }

        else if (opcion == 3) {
            string buscar;
            cout << "Codigo a buscar: "; cin >> buscar;
            bool hallado = false;
            for (int i = 0; i < inventario.size(); i++) {
                if (inventario[i]->codigo == buscar) {
                    inventario[i]->mostrarInfo();
                    hallado = true;
                }
            }
            if (!hallado) cout << "No encontrado." << endl;
        }

        else if (opcion == 4) {
            string mod;
            cout << "Codigo a editar: "; cin >> mod;
            for (int i = 0; i < inventario.size(); i++) {
                if (inventario[i]->codigo == mod) {
                    cout << "Nuevo Nombre: "; cin >> inventario[i]->nombre;
                    cout << "Nuevo Estado: "; cin >> inventario[i]->estado;
                    cout << "Actualizado." << endl;
                }
            }
        }

        else if (opcion == 5) {
            string borrar;
            cout << "Codigo a eliminar: "; cin >> borrar;
            for (int i = 0; i < inventario.size(); i++) {
                if (inventario[i]->codigo == borrar) {
                    delete inventario[i]; // Liberamos la memoria del objeto
                    inventario.erase(inventario.begin() + i);
                    cout << "Eliminado." << endl;
                    break;
                }
            }
        }

        else if (opcion == 6) {
            cout << "\n--- REPORTE FINAL ---" << endl;
            cout << "Total equipos: " << inventario.size() << endl;
        }

    } while (opcion != 7);

    // Limpiar memoria antes de salir
    for (int i = 0; i < inventario.size(); i++) {
        delete inventario[i];
    }

    return 0;
}
