#include<iostream>
using namespace std;

struct Stack{
    int *S;
    int size;
    int top;
};

void push(Stack *st, int x){
    if(st->top==st->size-1){
        cout<<"Overflow condition, stack full!";
        return;
    }
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(Stack *st){
    int x =-1;
    if(st->top==-1){
        cout<<"Unserflow condition. Stack might be empty!";
    }
    else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}
int peek(Stack *st,int pos){
    int x =-1;
    if(st->top-pos+1<0){
        cout<<"Underflow condition or invalid position!";
    }
    else{
        x = st->S[st->top-pos+1];
    }
    return x;
}

bool isEmpty(Stack *st){
    if(st->top==-1){
        return true;
    }
    else{ return false; }
}

bool isFull(Stack *st){
    if(st->top == st->size-1){
        return true;
    }
    else{ return false;}
}

int main(){
    struct Stack st;
    st.top=-1;
    cout<<"Enter stack size :";
    cin>>st.size;
    st.S = new int[st.size];

    int n,value;
    cout<<"How many elements for now ?";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Element "<<i<<" ";
        cin>>value;
        push(&st,value);
    }

    
    isEmpty(&st) ? cout<<"Stack is empty!"<<endl: cout<<"Stack is not empty!"<<endl;
    isFull(&st)? cout<<"Stack is full don't add any further elements "<<endl: cout<<"Stack is not empty can add elements"<<endl;

    int pos;
    cout<<"Enter position to get element ";
    cin>>pos;
    int elem = peek(&st,pos);
    cout<<"At "<<pos<<" we have "<<elem<<endl;

    cout<<"Deleting the element at top of stack "<<endl;
    int del_elem = pop(&st);
    cout<<"Deleted "<<del_elem<<endl;
    return 0;
}