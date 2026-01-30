#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyCircularLL{
public:
    Node *head;
    Node*tail;

    DoublyCircularLL(){
        head = nullptr;
        tail =nullptr;
    }
    void display();
    void insert(int value);
    ~DoublyCircularLL(){
        if(!head){ return;}
            Node *temp = head->next;
            while(temp!=head){
                Node * nextN = temp->next;
                delete temp;
                temp = nextN;
            }
            head = tail =nullptr;
            cout<<"Destuctir called. Everything destroyed"<<endl;
    }

};

void DoublyCircularLL :: display(){
    Node *temp = head;
    do{
        cout<<temp->data<<"<->";
        temp=temp->next;
    }while(temp->next!=head);
    cout<<endl;
    cout<<"End of list , starts from first element again!"<<endl;
}

void DoublyCircularLL :: insert(int value){
    Node * newN = new Node(value);

    if(!head){
        head = tail = newN;
    }
    else{
        tail->next = newN;
        tail =newN;
        tail->next = head;
    }
}

int main(){
    DoublyCircularLL dcll;
    int n,value;
    cout<<"how many elements in DCLL ? ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Element "<<i<<" ";
        cin>>value;
        dcll.insert(value);
    }
    cout<<"The dcll is ";
    dcll.display();
    return 0;
}