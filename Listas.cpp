#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* append(Node* head, int val) {
    if (head == nullptr) {
        return new Node(val);
    }
    head->next = append(head->next, val);
    return head;
}

Node* remove(Node* head, int val) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->data == val) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    head->next = remove(head->next, val);
    return head;
}

void display(Node* head) {
    if (head == nullptr) {
        std::cout << "nullptr" << std::endl;
        return;
    }
    std::cout << head->data << " -> ";
    display(head->next);
}

int main() {
    Node* list = nullptr;

    list = append(list, 10);
    list = append(list, 20);
    list = append(list, 30);
    display(list);

    list = remove(list, 20);
    display(list);

    list = remove(list, 10);
    display(list);

    list = remove(list, 30);
    display(list);

    return 0;
}