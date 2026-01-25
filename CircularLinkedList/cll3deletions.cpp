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
        void deleteAtHead();
        void deleteAfterPos(int position);
        void deleteBeforePos(int position);
        void deleteAtTail();
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

void CircularLinkedList :: deleteAtHead(){
    if (!head) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
}
void CircularLinkedList :: deleteAtTail(){
     if (!head) return;

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
        tail->next = head;
}
void CircularLinkedList :: deleteAfterPos(int position){
    if (!head || head == tail) return;

        Node* temp = head;
        for (int i = 1; i < position; i++) {
            temp = temp->next;
            if (temp == head) return;
        }

        Node* del = temp->next;

        if (del == head) return;

        temp->next = del->next;

        if (del == tail) {
            tail = temp;
            tail->next = head;
        }

        delete del;
}
void CircularLinkedList :: deleteBeforePos(int position){
    if (!head || head == tail || position <= 1) return;

        if (position == 2) {
            deleteAtHead();
            return;
        }

        Node* prev = head;
        for (int i = 1; i < position - 2; i++) {
            prev = prev->next;
            if (prev->next == head) return;
        }

        Node* del = prev->next;
        prev->next = del->next;

        delete del;
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

    //Delete at head
    cout<<"Deleting at head ";
    cll.deleteAtHead();
    cll.display();

    //Deleting  at tail
    cout<<"Deleting at tail ";
    cll.deleteAtTail();
    cll.display();

    //Insert after pos
    int position;
    cout<<"Enter postion after which element to be deleted ";
    cin>>position;
    cll.deleteAfterPos(position);
    cll.display();

    //Insert before position
    cout<<"Enter position before which elem to be deleted ";
    cin>>position;
    cll.deleteBeforePos(position);
    cll.display();

    return 0;

}