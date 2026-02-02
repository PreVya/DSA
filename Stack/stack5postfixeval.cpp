#include<iostream>
#include<stack>
using namespace std;

int applyOperator(int y, int x, char op) {
    switch (op) {
        case '+': return y + x;
        case '-': return y - x;
        case '*': return y * x;
        case '/': return y / x;   // assume x != 0
    }
    return 0;
}

int postfixEval(string postfix){
    stack <int> st;
    for(auto c:postfix){
        if (isdigit(c)) {
            st.push(c - '0');
        }
        else if (c=='+' || c=='-' || c=='*' || c=='/'){
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            int result = applyOperator(y, x, c);
            st.push(result);
        }
    }
    return st.top();
}

int main(){
    string postfix;
    cout<<"Enter postfix expression for evaluation ";
    cin>>postfix;

    cout<<"Evalution of "<<postfix<<" is "<<postfixEval(postfix)<<endl;
    return 0;
}