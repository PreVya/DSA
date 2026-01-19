#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void display(Node* head){
    cout<<"List is "<<endl;
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}   

void insertSorted(Node *head,int value){
    Node * temp = new Node {value,nullptr};
    if(head == NULL || value <= head->data){
        temp->next = head;
        head = temp;
        return;
    }
    Node *p = head;
    Node *q = NULL;

    while(p != NULL && p->data < value){
        q = p;
        p = p->next;
    }

    q->next = temp;
    temp->next = p;

    display(head);
}

int main(){
    Node *head =nullptr,*tail=nullptr;
    int value,n;
    cout<<"How many elements in LL? ";
    cin>>n;

    cout<<"Enter ll in sorted manner i.e. elements in ascending order only ";
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i<<" ";
        cin>>value;

        Node *newNode = new Node{value,nullptr};
        if(!head){ 
            head =tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    cout<<"Initial lined list :";
    display(head);

    int elem;
    cout<<"Enter elemt to put it in LL at its right place as per value ";
    cin>>elem;
    insertSorted(head,elem);
    return 0;
}