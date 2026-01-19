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

void deleteHead(Node* &head,Node *&tail){
    if(!head){
        cout<<"List is empty!";
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    display(head);
}

void deleteTail(Node * &head,Node *&tail){
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = nullptr;

    display(head);
}

void deleteAfter(Node *&head, Node*&tail, int position){
    Node*temp = head;
    for (int i = 0; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        cout << "Invalid position\n";
        return;
    }
    Node * delNode = temp->next;
    temp->next = delNode->next;

    if (delNode == tail) {
        tail = temp;
    }

    delete delNode;
    display(head);
}

void deleteBefore(Node *&head, Node *&tail,int position){
    Node *temp = head;
    for (int i = 0; i < position - 2 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        cout << "Invalid position\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;

    delete delNode;

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

    int position1;
    cout<<"Enter position after which node will be deleted ";
    cin>>position1;
    deleteAfter(head,tail,position1);

    int position2;
    cout<<"Enter position before which node will be deleted ";
    cin>>position2;
    deleteBefore(head,tail,position2);

    cout<<"Deleting the first element of list ";
    deleteHead(head,tail);

    cout<<"Deleting the last element of list ";
    deleteTail(head,tail);

    return 0;
}