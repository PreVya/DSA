#include<iostream>
using namespace std;

//TC+ O(1) !!!!! This is of constant time complexity
int fun(int n){
    if(n>100){
        return n-10;
    } 
    else {
        return fun(fun(n+11));
    }
    return 0;
}
int main(){
    int x = 95;
    cout<<fun(x);
    return 0;
}