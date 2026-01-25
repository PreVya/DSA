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
        void insert(int value){
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
        void display(){
            Node *temp = head;
            do{
                cout<<temp->data<<"->";
                temp=temp->next;
            }while(temp->next!=head);
            cout<<endl;
            cout<<"End of list , starts from first element again!"<<endl;
        }
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
    return 0;

}