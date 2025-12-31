#include<iostream>
using namespace std;

//TC O(2^n)
int toh(int n, char A, char B, char C){
    if(n==1){
        cout<<"Move disk 1 from rod "<<A<<" to rod "<<C<<endl;
        return 0;
    }
    toh(n-1,A,C,B);
    cout<<"Move disk "<<n<<" from rod "<<A<<" to rod "<<C<<endl;
    toh(n-1,B,A,C);
    return 0;
}

int main(){
    int n;
    cout<<"Enter number of disks: ";
    cin>>n;
    toh(n,'A','B','C');
    return 0;
}