#include<iostream>
using namespace std;

class Node{
public :
    int data;
    Node *next;
    Node(int value){
        data = value;
        next =nullptr;
    }

};

class Queue{
public:
Node *head;
Node *tail;

    Queue(){
        head =nullptr;
        tail = nullptr;

    }
    void displayQueue();
    void enqueue(int value);
    void dequeue();
    ~Queue(){
        Node *temp = head;
        while(temp!=nullptr){
            Node *newN = temp->next;
            delete temp;
            temp = newN;
        }
        head = nullptr;

    }
};

void Queue :: displayQueue(){
    Node *temp =head;
    cout<<"Queue: "<<endl;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
    cout<<endl;
}

void Queue :: enqueue(int value){
    Node *temp =  new Node(value);
    if(!head){ head =tail =temp; }
    else{
        tail->next = temp;
        tail = temp;
    }
    cout<<"After enqueue :"<<endl;
    displayQueue();

}

void Queue :: dequeue(){
    if(!head){
        cout << "Queue is empty\n";
        return;
    }
    Node *temp  = head;
    head = temp->next;
    delete temp;
    if(!head) tail = nullptr;
    cout<<"After dequeue :"<<endl;
    displayQueue();
}

int main(){
    Queue q;
    int n,value;
    cout<<"Enter how many elemnts in queue ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter elem "<<i<<" ";
        cin>>value;
        q.enqueue(value);
    }
    cout<<"Dequeuing...:";
    q.dequeue();
    return 0;
}