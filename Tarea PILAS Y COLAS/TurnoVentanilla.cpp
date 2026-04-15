#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> cola;

    cola.push(101);
    cola.push(102);
    cola.push(103);

    cout << "Atendiendo: " << cola.front() << endl;
    cola.pop();

    cout << "Atendiendo: " << cola.front() << endl;
    cola.pop();

    cout << "Siguiente turno: " << cola.front() << endl;

    return 0;
}
