#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;      // Arreglo para almacenar los elementos de la cola
    int front;     // Índice del primer elemento de la cola
    int rear;      // Índice del último elemento de la cola
    int capacity;  // Capacidad máxima de la cola
    int count;     // Número actual de elementos en la cola

public:
    // Constructor para inicializar la cola
    Queue(int size) {
        arr = new int[size]; // Crear el arreglo
        capacity = size;     // Establecer la capacidad
        front = 0;          // Inicialmente el frente es 0
        rear = -1;          // Inicialmente no hay elementos, rear es -1
        count = 0;          // Inicialmente la cola está vacía
    }

    // Destructor para liberar la memoria
    ~Queue() {
        delete[] arr; // Liberar el arreglo
    }

    // Método para agregar un elemento a la cola
    void enqueue(int x) {
        if (count == capacity) {
            cout << "Cola llena. No se puede agregar " << x << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Mover el índice trasero circularmente
        arr[rear] = x;                 // Agregar el elemento
        count++;                       // Incrementar el contador
        cout << x << " agregado a la cola." << endl;
    }

    // Método para eliminar el primer elemento de la cola
    int dequeue() {
        if (isEmpty()) {
            cout << "Cola vacía. No se puede eliminar." << endl;
            return -1; // Retornar -1 si la cola está vacía
        }
        int item = arr[front]; // Obtener el elemento del frente
        front = (front + 1) % capacity; // Mover el índice del frente circularmente
        count--; // Decrementar el contador
        return item; // Retornar el elemento eliminado
    }

    // Método para obtener el primer elemento sin eliminarlo
    int frontElement() {
        if (isEmpty()) {
            cout << "Cola vacía." << endl;
            return -1; // Retornar -1 si la cola está vacía
        }
        return arr[front]; // Retornar el elemento del frente
    }

    // Método para verificar si la cola está vacía
    bool isEmpty() {
        return count == 0; // Retornar true si el contador es 0
    }

    // Método para obtener el tamaño actual de la cola
    int size() {
        return count; // Retornar el número de elementos en la cola
    }
};

int main() {
    Queue queue(5); // Crear una cola de capacidad 5

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Elemento del frente: " << queue.frontElement() << endl; // Debería mostrar 10

    cout << "Elemento eliminado: " << queue.dequeue() << endl; // Debería eliminar 10
    cout << "Elemento del frente: " << queue.frontElement() << endl; // Debería mostrar 20

    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60); // Esto debería mostrar un mensaje de cola llena

    cout << "Tamaño de la cola: " << queue.size() << endl; // Debería mostrar 4

    return 0;
}