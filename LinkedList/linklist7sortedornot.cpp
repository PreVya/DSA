#include<iostream>
#include <climits>
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

bool sortedOrNot(Node *head){
    int x = INT_MIN;
    Node * temp =head;
    while(temp!=NULL){
        if(temp->data<x){
            return false;
        }
        x = temp->data;
        temp = temp->next;
    }
    return true;
}

int main(){
    Node *head =nullptr,*tail=nullptr;
    int value,n;
    cout<<"How many elements in LL? ";
    cin>>n;

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

    cout<<"Checking if LL is sorted ..."<<endl;
    bool sort = sortedOrNot(head);
    sort?cout<<"LL is sorted!":cout<<"LL is unsorted!";

    return 0;
}