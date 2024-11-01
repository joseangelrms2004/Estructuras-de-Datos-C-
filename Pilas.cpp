#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

int stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX_SIZE - 1;
}

void push(int x) {
    if (isFull()) {
        cout << "Pila llena. No se puede agregar " << x << endl;
        return;
    }
    stack[++top] = x; 
    cout << x << " agregado a la pila." << endl;
}

int pop() {
    if (isEmpty()) {
        cout << "Pila vacía. No se puede eliminar." << endl;
        return -1; 
    }
    return stack[top--]; 
}

int peek() {
    if (isEmpty()) {
        cout << "Pila vacía." << endl;
        return -1;
    }
    return stack[top]; 
}

int size() {
    return top + 1;
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Elemento superior: " << peek() << endl;

    cout << "Elementos eliminados: " << pop() << endl;
    cout << "Elemento superior: " << peek() << endl; 

    push(40);
    push(50);
    push(60);
    cout << "Tamaño de la pila: " << size() << endl; 

    return 0;
}