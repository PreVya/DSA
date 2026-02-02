#include<iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> st;
    int n,val;
    cout<<"ENter num of elems in stack ";
    cin>>n;
    for(int i=0; i<n;i++){
        cout<<"Enter elem "<<i<<" ";
        cin>>val;
        st.push(val);
    }
    cout<<"Top elem of stack "<<st.top()<<endl;
    st.pop();
    cout<<"After deleting top elem "<<st.top()<<endl;
    cout<<"Current eleme in stack "<<st.size()<<endl;

    while (!st.empty()) {
        st.pop();
    }

    st.empty()==1? cout<<"Stack is now empty !"<<endl : cout<<"stack is not empty!"<<endl;
    return 0;
}