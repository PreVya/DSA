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
    void insertAtHead(int value);
    void insertAtTail(int value);
    void insertAfterPos(int value,int position);
    void insertBeforePos(int value, int position);
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

void DoublyLinkedList :: insertAtHead(int value){
    Node *temp = new Node(value);
    if(!head){
        head = tail = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void DoublyLinkedList :: insertAtTail(int value){
    
    Node* newN = new Node(value);

        if (!head) {
            head = tail = newN;
        } else {
            tail->next = newN;
            newN->prev = tail;
            tail = newN;
        }
}

void DoublyLinkedList :: insertAfterPos(int value, int position){
    Node * newN = new Node (value);
    Node *temp=head;

    for(int i=0;i<position-1 && temp ;i++){
        temp=temp->next;
    }
    newN->next = temp->next;
    newN->prev = temp;
    if(temp->next){
        temp->next->prev = newN;
    }
    else{ tail =newN; }
    temp->next = newN;
}

void DoublyLinkedList :: insertBeforePos(int value, int position){
    if (position == 1) {
            insertAtHead(value);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position && temp; i++) {
            temp = temp->next;
        }
        if (!temp) return;

        Node* newN = new Node(value);

        newN->prev = temp->prev;
        newN->next = temp;
        temp->prev->next = newN;
        temp->prev = newN;
        
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

    //Insert at head
    cout<<"Enter value to insert at head ";
    cin>>value;
    dll.insertAtHead(value);
    dll.display();

    //Insert at tail
    cout<<"Enter value to insert at tail ";
    cin>>value;
    dll.insertAtTail(value);
    dll.display();

    //Insert after pos
    int position;
    cout<<"Enter value to insert after pos ";
    cin>>value;
    cout<<"Enter position ";
    cin>>position;
    dll.insertAfterPos(value,position);
    dll.display();

    //Insert before positon
    cout<<"Enter value to insert before pos ";
    cin>>value;
    cout<<"Enter position ";
    cin>>position;
    dll.insertBeforePos(value,position);
    dll.display();
    return 0;
}