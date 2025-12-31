#include<iostream>
using namespace std;

//TC = O(n^2)
double calculate_e1(int x, int n){
    static double p=1,f=1;
    double r;
    if(n==0){
        return 1;
    }
    else{
        r = calculate_e1(x,n-1);
        p=p*x;
        f=f*n;
        return r + p/f;
    }
}

//TC= O(n) //also called as Horner's Rule
double calculate_e2(int x, int n){
    static double s=1;
    if(n==0){
        return s;
    }
    else{
        s = 1+x*s/n;
        return calculate_e2(x,n-1);
    }
}

int main(){
    int x,n;
    cout<<"enter values of x (e^x and x is uaually =2) and n (nth term upto wi=hcih you want series): ";
    cin>>x>>n;
    cout<<"Value of e using method 1 is "<<calculate_e1(x,n)<<endl;
    cout<<"Value of e using method 2 is "<<calculate_e2(x,n);
    return 0;
}