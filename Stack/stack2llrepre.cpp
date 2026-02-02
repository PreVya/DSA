#include <iostream>
using namespace std;

class Node{
public :
    int data;
    Node *next;
    Node(int value){
        data = value;
        next =nullptr;
    }

};

class Stack{
public:
Node *head;

    Stack(){
        head =nullptr;

    }
    void displayStack();
    void insertStack(int value);
    void deleteStack();
    ~Stack(){
        Node *temp = head;
        while(temp!=nullptr){
            Node *newN = temp->next;
            delete temp;
            temp = newN;
        }
        head = nullptr;

    }
};

void Stack :: displayStack(){
    Node *temp =head;
    cout<<"stack displaying from top to bottom "<<endl;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
    cout<<endl;
}

void Stack :: insertStack(int value){
    Node *temp =  new Node(value);
    temp->next = head;
    head = temp;
    cout<<"After insertion :"<<endl;
    displayStack();

}

void Stack :: deleteStack(){
    Node *temp  = head;
    head = temp->next;
    delete temp;
    cout<<"After deltion stack :"<<endl;
    displayStack();
}

int main(){
    Stack st;
    int n,value;
    cout<<"Enter how many elemnt sin stack ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter elem "<<i<<" ";
        cin>>value;
        st.insertStack(value);
    }
    cout<<"Deleting top elemnt :";
    st.deleteStack();
    return 0;
}