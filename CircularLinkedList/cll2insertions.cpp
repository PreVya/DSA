#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList{
    private:
        Node* head;
        Node *tail;
    public :
        CircularLinkedList(){
            head = nullptr;
            tail = nullptr;
        }
        void insert(int value);
        void display();
        void insertAtHead(int value);
        void insertAfterPos(int value, int position);
        void insertBeforePos(int value, int position);
        void insertAtTail(int value);
        ~CircularLinkedList(){
            if(!head){ return;}
            Node *temp = head->next;
            while(temp!=head){
                Node * nextN = temp->next;
                delete temp;
                temp = nextN;
            }
            head = tail =nullptr;
            cout<<"Destuctir called. Everything destroyed"<<endl;

        }
    
};

void CircularLinkedList :: insert(int value){
    Node * newN = new Node(value);

    if(!head){
         head = tail = newN;
    }
    else{
        tail->next = newN;
        tail =newN;
        tail->next = head;
    }
}

void CircularLinkedList ::  display(){
    Node *temp = head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
    cout<<"End of list , starts from first element again!"<<endl;
}

void CircularLinkedList :: insertAtHead(int value){
    Node* newN = new Node(value);

    if (!head) {
        head = tail = newN;
        tail->next = head;
    } else {
        newN->next = head;
        head = newN;
        tail->next = head;
    }
    cout<<"Display after insertion at head "<<endl;
    display();
}
void CircularLinkedList :: insertAtTail(int value){
     Node* newN = new Node(value);

    if (!head) {
        head = tail = newN;
        tail->next = head;
    } else {
        tail->next = newN;
        tail = newN;
        tail->next = head;
    }
    cout<<"Display after insertion at tail "<<endl;
    display();
}
void CircularLinkedList :: insertAfterPos(int value, int position){
    if (position == 1) {
        insertAtHead(value);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position; i++) {
        temp = temp->next;
        if (temp == head) return;  // invalid position
    }

    Node* newN = new Node(value);
    newN->next = temp->next;
    temp->next = newN;

    cout<<"Display after insertion at position "<<position<<endl;
    display();
}
void CircularLinkedList :: insertBeforePos(int value,int position){
    if (position == 1) {
        insertAtHead(value);
        return;
    }

    Node* prev = head;
    for (int i = 1; i < position - 1; i++) {
        prev = prev->next;
        if (prev->next == head) return;
    }

    Node* newN = new Node(value);
    newN->next = prev->next;
    prev->next = newN;

    cout<<"Display (before) insertion at position "<<position<<endl;
    display();

}

int main(){
    CircularLinkedList cll;
    int value,n;
    cout<<"how many elements in the list ?";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"element "<<i<<" ";
        cin>>value;
        cll.insert(value);
    }
    cll.display();

    //Insert at head
    cout<<"Enter value to insert at head ";
    cin>>value;
    cll.insertAtHead(value);

    //Insert at tail
    cout<<"Enter value o insert at tail ";
    cin>>value;
    cll.insertAtTail(value);

    //Insert after pos
    int position;
    cout<<"Enter position after which elem ti be inserted ";
    cin>>position;
    cout<<"Enter element ";
    cin>>value;
    cll.insertAfterPos(value,position);

    //Insert before position
    cout<<"Enter position before which elem ti be inserted ";
    cin>>position;
    cout<<"Enter element ";
    cin>>value;
    cll.insertBeforePos(value,position);

    return 0;

}