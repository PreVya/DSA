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
    return 0;
}