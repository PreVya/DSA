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
    void reverse();
    Node *returnHead(){ return head;}
    void reverseRecur(Node *head);
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

void DoublyLinkedList :: reverse(){
    
    Node* curr = head;
    Node* temp = nullptr;

    while(curr != nullptr){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if(temp != nullptr){
        head = temp->prev;
    }
}

void DoublyLinkedList :: reverseRecur(Node *curr){
    if(curr == nullptr)
        return;

    Node* temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;

    if(curr->prev == nullptr){
        head = curr;
        return;
    }

    reverseRecur(curr->prev);
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
    cout<<"reversing simply without recursion ";
    dll.reverse();
    dll.display();
    cout<<"Reversing with recursion ";
    Node *head = dll.returnHead();
    dll.reverseRecur(head);
    dll.display();
    return 0;
}