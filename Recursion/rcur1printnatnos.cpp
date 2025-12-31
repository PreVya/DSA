#include <iostream>
using namespace std;

// TC= O(n)
void natural_nos(int n){
    if(n>0){
        cout << n << " ";
        natural_nos(n-1);
    }
}
int main(){
    int count = 10;
    natural_nos(count);
    return 0;
}