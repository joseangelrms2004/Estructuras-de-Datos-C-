#include <iostream>
using namespace std;

const int MAX = 5; // Capacidad máxima de la cola
int arr[MAX]; // Arreglo para almacenar los elementos de la cola
int front = 0; // Índice del primer elemento de la cola
int rear = -1; // Índice del último elemento de la cola
int count = 0; // Número actual de elementos en la cola

// Función para verificar si la cola está vacía
bool isEmpty() {
    return count == 0;
}

// Función para agregar un elemento a la cola
void enqueue(int x) {
    if (count == MAX) {
        cout << "Cola llena. No se puede agregar " << x << endl;
        return;
    }
    rear = (rear + 1) % MAX; // Mover el índice trasero circularmente
    arr[rear] = x;           // Agregar el elemento
    count++;                 // Incrementar el contador
    cout << x << " agregado a la cola." << endl;
}

// Función para eliminar el primer elemento de la cola
int dequeue() {
    if (isEmpty()) {
        cout << "Cola vacía. No se puede eliminar." << endl;
        return -1; // Retornar -1 si la cola está vacía
    }
    int item = arr[front]; // Obtener el elemento del frente
    front = (front + 1) % MAX; // Mover el índice del frente circularmente
    count--; // Decrementar el contador
    return item; // Retornar el elemento eliminado
}

// Función para obtener el primer elemento sin eliminarlo
int frontElement() {
    if (isEmpty()) {
        cout << "Cola vacía." << endl;
        return -1; // Retornar -1 si la cola está vacía
    }
    return arr[front]; // Retornar el elemento del frente
}

// Función para obtener el tamaño actual de la cola
int size() {
    return count; // Retornar el número de elementos en la cola
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Elemento del frente: " << frontElement() << endl; // Debería mostrar 10

    cout << "Elemento eliminado: " << dequeue() << endl; // Debería eliminar 10
    cout << "Elemento del frente: " << frontElement() << endl; // Debería mostrar 20

    enqueue(40);
    enqueue(50);
    enqueue(60); // Esto debería mostrar un mensaje de cola llena

    cout << "Tamaño de la cola: " << size() << endl; // Debería mostrar 4

    return 0;
}