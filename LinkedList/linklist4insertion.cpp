#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void display(struct Node *head){
    cout<<"List is :"<<endl;
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtHead(struct Node *&head,struct Node *&tail,int value){
    Node *newNode = new Node{value,head};
    head = newNode;

    if(tail == nullptr){
        tail = newNode;
    }

    display(head);
}

void insertAtTail(struct Node *head,struct Node *tail,int value){
    Node *newNode = new Node{value,nullptr};

    if(!head){
        head = tail= newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
    display(head);
}

void insertAfterPosition(struct Node *head,struct Node *tail,int position,int value){
    Node *temp = head;

    for(int i=0;i<position && temp!=NULL;i++){
        temp = temp->next;

    }
    if(temp == nullptr){
        cout<<"Invalid position or tail insertion";
        return;
    }
    Node *newNode = new Node{value,temp->next};
    temp-> next =newNode ;

    display(head);

}

void insertBrforePosition(struct Node *head,struct Node *tail,int position,int value){
    Node *temp=head;

    for(int i=0;i< position-1 && temp!=NULL;i++){
        temp = temp->next;
    }

    if(temp == nullptr || temp->next==nullptr){
        cout<<"invalid pointer or last node";
        return;
    }
    else{
        Node *newNode = new Node{value,temp->next};
        temp->next = newNode;
    }

    display(head);
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

    int elemAtBeg;
    cout<<"Enter element to insert at the beginning ";
    cin>>elemAtBeg;
    insertAtHead(head,tail,elemAtBeg);

    int elemAtEnd;
    cout<<"Enter element to insert at end";
    cin>>elemAtEnd;
    insertAtTail(head,tail,elemAtEnd);
    
    int elemAfter,position1;
    cout<<"Enter element to enter after a position ";
    cin>>elemAfter;
    cout<<"Ente he position ";
    cin>>position1;
    insertAfterPosition(head,tail,position1,elemAfter);

    int elemBefore, position2;
    cout<<"Enter element to insert before a position ";
    cin>>elemBefore;
    cout<<"Enter position ";
    cin>>position2;
    insertBrforePosition(head,tail,position2,elemBefore);

    return 0;
}