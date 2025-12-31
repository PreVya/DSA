#include<iostream>
using namespace std;

struct Array{
    int *A;
    int size;
    int length;
};

void display(struct Array *arr){
    cout<<"Elements are :";
    for(int i=0;i<arr->length;i++){
        cout<<arr->A[i]<<" ";
    }
    cout<<endl;
}

int findMax(struct Array *arr){
    int max = arr->A[0];
    for(int i=1;i<arr->length;i++){
        if(arr->A[i]>max){
            max = arr->A[i];
        }
    }
    return max;
}
int main(){
    struct Array arr;
    cout<<"Enter array size :";
    cin>>arr.size;

    arr.A = new int [arr.size];

    cout<<"How many elements currently? :";
    cin>>arr.length;    

    cout<<"Enter elements :";
    for(int i=0;i<arr.length;i++){
        cin>>arr.A[i];
    }
    int key;
    cout<<"Enter the sum value to find pairs :";
    cin>>key;
    display(&arr);
    int max = findMax(&arr);

    struct Array hashArr;
    hashArr.size = max+1;
    hashArr.length = max+1;
    hashArr.A = new int [hashArr.size];
    for(int i = 0; i < hashArr.size; i++) hashArr.A[i] = 0;

    for(int i=0;i<arr.length;i++){
        hashArr.A[arr.A[i]] =1;
    }

    for(int i=0;i<hashArr.length-1;i++){
        if(hashArr.A[i]==1){
            int diff = key -i;
            if(hashArr.A[diff]>0 && diff >=0 && diff<=max){
                cout<<"Pair is :"<<i<<" and "<<diff<<endl;
            }
            if (arr.A[i] <= max) {
                hashArr.A[arr.A[i]] = 2;
                hashArr.A[diff] = 2;
            }
        }
    }
   return 0;
}