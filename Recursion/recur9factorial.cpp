#include<iostream>
using namespace std;

//TC= O(n)
long factorial (int n){
    if (n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

int main(){
    int f;
    cout<<"Enter num to get factorial: ";
    cin>>f;
    cout<<"Factorial of "<<f<<" is "<<factorial(f);
    return 0;
}