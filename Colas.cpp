#include <iostream>
using namespace std;

const int MAX = 5; 
int arr[MAX]; 
int front = 0;
int rear = -1;
int count = 0;


bool isEmpty() {
    return count == 0;
}


void enqueue(int x) {
    if (count == MAX) {
        cout << "Cola llena. No se puede agregar " << x << endl;
        return;
    }
    rear = (rear + 1) % MAX; 
    arr[rear] = x;           
    count++;                 
    cout << x << " agregado a la cola." << endl;
}


int dequeue() {
    if (isEmpty()) {
        cout << "Cola vacía. No se puede eliminar." << endl;
        return -1; 
            }
    int item = arr[front]; 
       front = (front + 1) % MAX; 
    count--; 
    return item; 
}


int frontElement() {
    if (isEmpty()) {
        cout << "Cola vacía." << endl;
        return -1; 
    }
    return arr[front]; 
}


int size() {
    return count; 
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Elemento del frente: " << frontElement() << endl; 

    cout << "Elemento eliminado: " << dequeue() << endl; 
    cout << "Elemento del frente: " << frontElement() << endl; 

    enqueue(40);
    enqueue(50);
    enqueue(60);

    cout << "Tamaño de la cola: " << size() << endl; 

    return 0;
}