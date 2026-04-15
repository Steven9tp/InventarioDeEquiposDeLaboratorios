#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool balanceado(string exp) {
    stack<char> pila;

    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') {
            pila.push('(');
        } 
        else if (exp[i] == ')') {
            if (pila.empty()) {
                return false;
            }
            pila.pop();
        }
    }

    return pila.empty();
}

int main() {
    string exp;

    cout << "Ingrese expresion: ";
    getline(cin, exp);  // ?? IMPORTANTE (mejor que cin >>)

    if (balanceado(exp)) {
        cout << "Balanceado\n";
    } else {
        cout << "No balanceado\n";
    }

    return 0;
}
