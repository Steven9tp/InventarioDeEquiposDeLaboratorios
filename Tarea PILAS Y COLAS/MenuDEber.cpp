#include <iostream>
#include <stack>
using namespace std;

#define TAM 5

// ===== PILA =====
int pila[TAM];
int tope = -1;

bool pilaLlena() { return tope == TAM - 1; }
bool pilaVacia() { return tope == -1; }

void push(int x) {
    if (pilaLlena()) cout << "Error: Pila llena\n";
    else pila[++tope] = x;
}

void pop() {
    if (pilaVacia()) cout << "Error: Pila vacia\n";
    else cout << "Eliminado: " << pila[tope--] << endl;
}

void top() {
    if (pilaVacia()) cout << "Pila vacia\n";
    else cout << "Tope: " << pila[tope] << endl;
}

// ===== COLA =====
int cola[TAM];
int frente = 0, final = -1;

bool colaLlena() { return final == TAM - 1; }
bool colaVacia() { return frente > final; }

void enqueue(int x) {
    if (colaLlena()) cout << "Error: Cola llena\n";
    else cola[++final] = x;
}

void dequeue() {
    if (colaVacia()) cout << "Error: Cola vacia\n";
    else cout << "Atendido: " << cola[frente++] << endl;
}

void front() {
    if (colaVacia()) cout << "Cola vacia\n";
    else cout << "Primero: " << cola[frente] << endl;
}

// ===== PARÉNTESIS BALANCEADOS =====
bool balanceado(string exp) {
    stack<char> p;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') p.push('(');
        else if (exp[i] == ')') {
            if (p.empty()) return false;
            p.pop();
        }
    }
    return p.empty();
}

// ===== TURNOS =====
void simulacionTurnos() {
    int turnos[5] = {101,102,103};
    int f = 0;

    cout << "Atendiendo: " << turnos[f++] << endl;
    cout << "Atendiendo: " << turnos[f++] << endl;
    cout << "Siguiente turno: " << turnos[f] << endl;
}

// ===== MAIN =====
int main() {
    int op, sub, x;
    string exp;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Pila\n";
        cout << "2. Cola\n";
        cout << "3. Parentesis balanceados\n";
        cout << "4. Turnos en ventanilla\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        switch(op) {

        case 1:
            do {
                cout << "\n-- PILA --\n";
                cout << "1. Push\n2. Pop\n3. Top\n0. Salir\n";
                cin >> sub;

                if(sub==1){
                    cout << "Valor: ";
                    cin >> x;
                    push(x);
                }
                else if(sub==2) pop();
                else if(sub==3) top();

            } while(sub!=0);
            break;

        case 2:
            do {
                cout << "\n-- COLA --\n";
                cout << "1. Enqueue\n2. Dequeue\n3. Front\n0. Salir\n";
                cin >> sub;

                if(sub==1){
                    cout << "Valor: ";
                    cin >> x;
                    enqueue(x);
                }
                else if(sub==2) dequeue();
                else if(sub==3) front();

            } while(sub!=0);
            break;

        case 3:
            cin.ignore();
            cout << "Ingrese expresion: ";
            getline(cin, exp);

            if(balanceado(exp))
                cout << "Balanceado\n";
            else
                cout << "No balanceado\n";
            break;

        case 4:
            simulacionTurnos();
            break;
        }

    } while(op != 0);

    return 0;
}
