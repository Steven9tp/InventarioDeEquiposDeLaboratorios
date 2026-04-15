#include <iostream>
using namespace std;

#define TAM 5

int pila[TAM];
int tope = -1;

bool isFull() {
    return tope == TAM - 1;
}

bool isEmpty() {
    return tope == -1;
}

void push(int x) {
    if (isFull()) {
        cout << "Error: Pila llena\n";
    } else {
        pila[++tope] = x;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Error: Pila vacia\n";
    } else {
        cout << "Eliminado: " << pila[tope--] << endl;
    }
}

void top() {
    if (isEmpty()) {
        cout << "Pila vacia\n";
    } else {
        cout << "Tope: " << pila[tope] << endl;
    }
}

void mostrar() {
    for (int i = tope; i >= 0; i--) {
        cout << pila[i] << endl;
    }
}

int main() {
    int op, x;

    do {
        cout << "\n--- PILA ---\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Mostrar\n0. Salir\n";
        cin >> op;

        switch(op) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> x;
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                top();
                break;
            case 4:
                mostrar();
                break;
        }

    } while(op != 0);

    return 0;
}
