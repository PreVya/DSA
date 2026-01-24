#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void display(Node * head){
    Node *temp= head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

struct Node* reverseLL(Node *head){
    Node *prev = nullptr;
    Node *curr = head;

    while(curr!=NULL){
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    Node *head=nullptr,*tail=nullptr;
    int n,value;
    cout<<"Enter number of elements in list :";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Element "<<i<<" ";
        cin>>value;

        Node *newN = new Node{value,nullptr};
        if(!head){ head = tail = newN;}
        else{
            tail->next = newN;
            tail = newN;
        }
    }
    cout<<"linked list is ";
    display(head);
    cout<<"Reversing using link reversal ..."<<endl;
    head = reverseLL(head);
    display(head);
    return 0;
}