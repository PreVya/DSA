#include<iostream>
using namespace std;

//complexity O(2^n)
int fibo1(int n){
    if(n<=1){
        return n;
    }
    else{
        return fibo1(n-2)+fibo1(n-1);
    }
}

//complexity O(n)
int fibo2(int n, int *F){
    if(n<=1){
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2]==-1){
            F[n-2] = fibo2(n-2,F);
        }
        if(F[n-1]==-1){
            F[n-1] = fibo2(n-1,F);

        }
    }
    return F[n-2]+F[n-1];
}

//complexity O(n)
void fibo3(int n,int *G){
    if(n<=1){
        G[n] = n;
        return;
    }
    else{
    if(G[n-1]==-1){
        fibo3(n-1,G);
    }
    if(G[n-2]==-1){
        fibo3(n-2,G);
    }
    }  
    G[n] = G[n-1]+G[n-2];

}
int main(){
    int x1,x2;
    cout<<"Enter nth term of fibonacci series: ";
    cin>>x1;
    fibo1(x1);
    cout<<"Normal recursion gives "<<fibo1(x1)<<" as "<<x1<<"th term of fibonacci series"<<endl;

    int *F;
    F =  new int[x1];
    for(int i=0;i<x1;i++){
        F[i] = -1;
    }
    cout<<"With array approach the "<<x1<<"th term is "<<fibo2(x1,F)<<endl;
    delete []F;

    
    cout<<"Enter how many terms of fibonacci series you want, we will print all: ";
    cin>>x2;
    int *G;
    G = new int[x2];
    for(int i=0;i<x2;i++){
        G[i] = -1;
    }
    cout<<"Fibonacci series using recursion with array is: ";
    fibo3(x2,G);
    for (int i = 0; i < x2; i++) {
        cout << G[i] << " ";
    }
    delete []G;
    return 0;
}