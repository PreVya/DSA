#include<iostream>
using namespace std;

class Node{
    public:
        int coeff;
        int exp;
        Node *next;
        Node(int c,int x){
            coeff = c;
            exp =x;
            next = nullptr;
            
        }
};

class Polynomial{
    public:
        Node *head;
        Node *tail;
        Polynomial(){
            head = nullptr;
            tail =nullptr;
        }
        void displayPoly();
        void insertTerm(int c, int x);
        ~Polynomial(){
            Node* temp = head;
            while (temp) {
                Node* nextN = temp->next;
                delete temp;
                temp = nextN;
            }
            head = tail = nullptr;
            cout<<"Destuctir called. Everything destroyed"<<endl;
        }
};

void Polynomial :: displayPoly(){
    cout<<"The polynomial is :"<<endl;
    Node *temp = head;
    while(temp!=NULL){
        if(temp->exp!=0){
            if(temp->coeff>0){
                cout<<"+"<<temp->coeff<<"*x^"<<temp->exp<<"  ";
            }
            else{
                cout<<temp->coeff<<"*x^"<<temp->exp<<"  ";
            }
            
        }
        else{
            temp->coeff>0 ? cout<<"+"<<temp->coeff<<"  " : cout<<temp->coeff<<"  ";
        }
        temp = temp->next;
    }
}

void Polynomial :: insertTerm(int c, int x){
    Node *newN = new Node(c,x);
    if(!head){ head = tail = newN;}
    else{
        tail->next = newN;
        tail = newN;
    }
}

int main(){
    Polynomial poly;
    int c,x,n;
    cout<<"How many terms in polynomial?";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Enter the coreff for term "<<i<<" ";
        cin>>c;
        cout<<"Enter the exponent for term "<<i<<" ";
        cin>>x;
        poly.insertTerm(c,x);
    }
    poly.displayPoly();
    return 0;
}