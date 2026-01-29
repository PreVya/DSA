#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void display();
    void insert(int value);
    void deleteAtHead();
    void deleteAtTail();
    void deleteAfterPos(int position);
    void deleteBeforePos(int position);
    ~DoublyLinkedList(){
        delete head;
        delete tail;
    }
};

void DoublyLinkedList :: display(){
    cout<<"In forward direction"<<endl;
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void DoublyLinkedList :: insert(int value){
    Node *newNode = new Node(value);
    if(!head){
        head = tail =newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoublyLinkedList :: deleteAtHead(){
    if(!head){
        return;
    }
    Node *temp = head;
    if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
}

void DoublyLinkedList :: deleteAtTail(){
    
    Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
}

void DoublyLinkedList :: deleteAfterPos(int position){
    Node* temp = head;
        for (int i = 1; i < position && temp; i++) {
            temp = temp->next;
        }
        if (!temp || !temp->next) return;

        Node* del = temp->next;
        temp->next = del->next;

        if (del->next)
            del->next->prev = temp;
        else
            tail = temp;

        delete del;
}

void DoublyLinkedList :: deleteBeforePos(int position){
    Node* temp = head;
        for (int i = 1; i < position && temp; i++) {
            temp = temp->next;
        }
        if (!temp || !temp->prev) return;

        Node* del = temp->prev;

        if (del->prev)
            del->prev->next = temp;
        else
            head = temp;

        temp->prev = del->prev;
        delete del;
        
}

int main(){
    DoublyLinkedList dll;
    int value,n;
    cout<<"how many elemetns in dll ?";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Element "<<i<<" ";
        cin>>value;
        dll.insert(value);
    }
    dll.display();

    //Delete at head
    cout<<"Deleting at head...";
    dll.deleteAtHead();
    dll.display();

    //Delete at tail
    cout<<"Deleting at tail...";
    dll.deleteAtTail();
    dll.display();

    //Delete after pos
    int position;
    cout<<"Enter position to delete before after pos ";
    cin>>position;
    dll.deleteAfterPos(position);
    dll.display();

    //Delete before positon
    cout<<"Enter position to delete before pos ";
    cin>>position;
    dll.deleteBeforePos(position);
    dll.display();
    return 0;
}