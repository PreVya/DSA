#include<iostream>
using namespace std;

//TC= O(n)
void funA(int);
void funB(int);

int main(){
    int x = 20;
    funA(x);
    return 0;
}

void funA(int x){
    if(x>0){
        cout<<x<<" ";
        funB(x-1);
    }
}

void funB(int x){
    if(x>1){
        cout<<x<<" ";
        funA(x/2);
    }
}