#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;      // Arreglo para almacenar los elementos de la pila
    int top;       // Índice del elemento superior de la pila
    int capacity;  // Capacidad máxima de la pila

public:
    // Constructor para inicializar la pila
    Stack(int size) {
        arr = new int[size]; // Crear el arreglo
        capacity = size;     // Establecer la capacidad
        top = -1;           // Inicialmente la pila está vacía
    }

    // Destructor para liberar la memoria
    ~Stack() {
        delete[] arr; // Liberar el arreglo
    }

    // Método para agregar un elemento a la pila
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Pila llena. No se puede agregar " << x << endl;
            return;
        }
        arr[++top] = x; // Incrementar el índice y agregar el elemento
        cout << x << " agregado a la pila." << endl;
    }

    // Método para eliminar el elemento superior de la pila
    int pop() {
        if (isEmpty()) {
            cout << "Pila vacía. No se puede eliminar." << endl;
            return -1; // Retornar -1 si la pila está vacía
        }
        return arr[top--]; // Retornar el elemento superior y decrementar el índice
    }

    // Método para obtener el elemento superior sin eliminarlo
    int peek() {
        if (isEmpty()) {
            cout << "Pila vacía." << endl;
            return -1; // Retornar -1 si la pila está vacía
        }
        return arr[top]; // Retornar el elemento superior
    }

    // Método para verificar si la pila está vacía
    bool isEmpty() {
        return top == -1; // Retornar true si el índice es -1
    }

    // Método para obtener el tamaño actual de la pila
    int size() {
        return top + 1; // Retornar el número de elementos en la pila
    }
};

int main() {
    Stack stack(5); // Crear una pila de capacidad 5

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Elemento superior: " << stack.peek() << endl; // Debería mostrar 30

    cout << "Elementos eliminados: " << stack.pop() << endl; // Debería eliminar 30
    cout << "Elemento superior: " << stack.peek() << endl; // Debería mostrar 20

    stack.push(40);
    stack.push(50);
    stack.push(60); // Esto debería mostrar un mensaje de pila llena

    cout << "Tamaño de la pila: " << stack.size() << endl; // Debería mostrar 4

    return 0;
}