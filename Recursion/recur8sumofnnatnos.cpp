#include<iostream>
using namespace std;

int sum(int n){
    if(n==0){
        return 0;
    }
    else{
        return n+sum(n-1);
    }
}

int main(){
    int x;
    cout<<"Enter a natural number: "<<" ";
    cin>>x;
    cout<<"Sum of first "<<x<<" natural numbers is "<<sum(x);
    return 0;
}