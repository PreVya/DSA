#include<iostream>
using namespace std;

//complexity time O(2^n)
int ncr(int n, int r){
    if(n==r || r==0){
        return 1;
    }
    else{
        return ncr(n-1,r-1) + ncr(n-1,r);
    }
}

int main(){
    int n,r;
    cout<<"Enter n and r with space in between ";
    cin>>n>>r;
    cout<<"nCr is "<<ncr(n,r);;
    return 0;
}