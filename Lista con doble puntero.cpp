#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

Node* append(Node* head, int val) {
    if (head == nullptr) {
        return new Node(val);
    }
    Node* newNode = new Node(val);
    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* remove(Node* head, int val) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->data == val) {
        Node* temp = head->next;
        if (temp != nullptr) {
            temp->prev = nullptr;
        }
        delete head;
        return temp;
    }
    head->next = remove(head->next, val);
    return head;
}

void displayForward(Node* head) {
    if (head == nullptr) {
        std::cout << "nullptr" << std::endl;
        return;
    }
    std::cout << head->data << " <-> ";
    displayForward(head->next);
}

void displayBackward(Node* tail) {
    if (tail == nullptr) {
        std::cout << "nullptr" << std::endl;
        return;
    }
    std::cout << tail->data << " <-> ";
    displayBackward(tail->prev);
}

Node* getTail(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    while (head->next != nullptr) {
        head = head->next;
    }
    return head;
}

int main() {
    Node* list = nullptr;

    list = append(list, 10);
    list = append(list, 20);
    list = append(list, 30);
    
    std::cout << "Display Forward: ";
    displayForward(list);

    list = remove(list, 20);
    std::cout << "After removing 20, Display Forward: ";
    displayForward(list);

    Node* tail = getTail(list);
    std::cout << "Display Backward: ";
    displayBackward(tail);

    list = remove(list, 10);
    std::cout << "After removing 10, Display Forward: ";
    displayForward(list);

    list = remove(list, 30);
    std::cout << "After removing 30, Display Forward: ";
    displayForward(list);

    return 0;
}