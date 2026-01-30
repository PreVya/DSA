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
bool duplicates(Node *head){
    Node *temp = head;

    while(temp!=nullptr){
        if (temp->data == temp->next->data){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void removeDuplicates(Node *head){
    Node *p = head;
    Node *q = p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next = q-> next;
            delete q;
            q = p->next;
        }
    }
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
    if(duplicates(head)){
        removeDuplicates(head);
        cout<<"After removing duplicates ";
        display(head);
    }
    else{ cout<<"No duplicates!";}
    return 0;

}