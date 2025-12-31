#include<iostream>
using namespace std;

//TC= O(n)
long power1(int m, int n){
    if(n==0){
        return 1;
    }
    else{
        return m*power1(m,n-1);
    }
}

//TC = O(log n)
long power2(int m, int n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return power2(m*m,n/2);
    }
    else{
        return m*power2(m*m,n/2);
    }
}

int main(){
    int m,n;
    cout<<"Enter base and index with a space in between ";
    cin>>m>>n;
    cout<<"Using simple recursion: "<<power1(m,n)<<endl;
    cout<<"Using efficient recursion: "<<power2(m,n);
    return 0;
}