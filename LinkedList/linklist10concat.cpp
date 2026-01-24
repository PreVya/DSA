#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void display(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void concat(Node *head1, Node *head2){
    Node *temp = head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = head2;
    head2 = NULL;
}

int main(){
    cout<<"For link list 1 "<<endl;
    Node *head1=nullptr,*tail1=nullptr;
    int n,value;
    cout<<"Enter number of elements in list :";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Element "<<i<<" ";
        cin>>value;

        Node *newN = new Node{value,nullptr};
        if(!head1){ head1 = tail1 = newN;}
        else{
            tail1->next = newN;
            tail1 = newN;
        }
    }
    cout<<"linked list is ";
    display(head1);
    
    
    cout<<"For link list 2 "<<endl;
    Node *head2=nullptr,*tail2=nullptr;
    cout<<"Enter number of elements in list :";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Element "<<i<<" ";
        cin>>value;

        Node *newN = new Node{value,nullptr};
        if(!head2){ head2 = tail2 = newN;}
        else{
            tail2->next = newN;
            tail2 = newN;
        }
    }
    cout<<"linked list is ";
    display(head2);
    cout<<"Concatenating ..."<<endl;
    concat(head1,head2);
    display(head1);
    return 0;
}