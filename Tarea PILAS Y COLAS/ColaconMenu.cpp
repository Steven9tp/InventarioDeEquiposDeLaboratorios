#include <iostream>
using namespace std;

#define TAM 5

int cola[TAM];
int frente = 0, final = -1;

bool isFull() {
    return final == TAM - 1;
}

bool isEmpty() {
    return frente > final;
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Error: Cola llena\n";
    } else {
        cola[++final] = x;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Error: Cola vacia\n";
    } else {
        cout << "Atendido: " << cola[frente++] << endl;
    }
}

void front() {
    if (isEmpty()) {
        cout << "Cola vacia\n";
    } else {
        cout << "Primero: " << cola[frente] << endl;
    }
}

void mostrar() {
    for (int i = frente; i <= final; i++) {
        cout << cola[i] << " ";
    }
    cout << endl;
}

int main() {
    int op, x;

    do {
        cout << "\n--- COLA ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Front\n4. Mostrar\n0. Salir\n";
        cin >> op;

        switch(op) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> x;
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                front();
                break;
            case 4:
                mostrar();
                break;
        }

    } while(op != 0);

    return 0;
}
