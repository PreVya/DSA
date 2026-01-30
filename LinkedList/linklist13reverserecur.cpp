#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void display(Node *head){
    Node *temp = head;

    while(temp!=nullptr){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
Node* reverse(Node *p, Node *q){
    if(p == NULL){
        return q; 
    }
    Node *next = p->next;
    p->next = q;
    return reverse(next, p);
}

int main(){
    Node *head = nullptr, *tail=nullptr;
    int n,value;

    cout<<"Enter number of lements in linked list :";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i<<" ";
        cin>>value;

        Node *newNode = new Node{value,nullptr};

        if(!head){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    cout<<"The list is: ";
    display(head);
    head = reverse(head,NULL);
    cout<<"Reversed linkde list :";
    display(head);
    return 0;

}