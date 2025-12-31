#include<iostream>
using namespace std;

// TC= O(2^n)
void fun(int x){
    if(x>0){
        cout<<x<<" ";
        fun(x-1);
        fun(x-1);
    }
}
int main(){
    int x = 4;
    fun(x);
    return 0;
}