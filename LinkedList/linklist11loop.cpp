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

bool isLoop(Node *head){
    Node *p =head;
    Node *q = head;
    do{
        p = p->next;
        q=q->next;
        if(q!=NULL){
            q=q->next;
        }
        if(p==q){
            return true;
        }
    }while(q!=NULL && p!=NULL);
    return false;
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
    //tail->next = head->next; //unncomment this for loop creation in the list
    cout<<"linked list is ";
    display(head); //comment this line to create loop in list else this will go no printing the list infinite times - program crashes.
    if(isLoop(head)){
        cout<<"Loop exists in the LL";
    }
    else{
        cout<<"Loop does not exist in LL";
    }
    return 0;
}