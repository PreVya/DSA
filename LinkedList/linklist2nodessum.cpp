#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

int totalElems(struct Node *p){
    int count=0;
    while(p!=nullptr){
        count++;
        p=p->next;
    }
    return count;
}

int sumElems(struct Node *p){
    int sum=0;
    while(p!=nullptr){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int main(){
    Node *head=nullptr, *tail=nullptr;
    int n,value;

    cout<<"Enter no. of lements in ll :";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"enter element "<<i<<" ";
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

    cout<<"The list is  ";
    Node *temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

    cout<<"No. of elements in ll :"<<totalElems(head)<<endl;
    cout<<"Sum of lements in ll :"<<sumElems(head)<<endl;
    return 0;
}