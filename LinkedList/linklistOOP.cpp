#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
        cout << "LinkedList destroyed, memory freed." << endl;
    }
};

int main() {
    LinkedList list;
    int n, value;

    cout << "Enter number of elements in linked list: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> value;
        list.insert(value);
    }

    cout << "The list is: ";
    list.display();

    return 0;
}
