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

void reverseLL(Node *head,int n){
    int arr[n];
    Node *temp = head;
    int i=0;
    while(temp!=NULL){
        arr[i] = temp->data;
        temp= temp->next;
        i++;
    }
    i--;
    temp = head;

    while(temp!=NULL){
        temp->data = arr[i];
        i--;
        temp=temp->next;
    }
}

int main(){
    Node *head =nullptr, *tail =nullptr;
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
    cout<<"Reversing using array"<<endl;
    reverseLL(head,n);
    display(head);
    return 0;
}