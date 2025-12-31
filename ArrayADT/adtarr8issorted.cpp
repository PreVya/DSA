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

bool isSorted(struct Array *arr){
    for(int i=0;i<arr->length -1;i++){
        if(arr->A[i]>arr->A[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    struct Array arr;
    cout<<"Enter array size :";
    cin>>arr.size;

    arr.A = new int [arr.size];

    cout<<"How many elements currently? :";
    cin>>arr.length;    

    cout<<"Enter all elements :";
    for(int i=0;i<arr.length;i++){
        cin>>arr.A[i];
    }

    display(&arr);

    if(isSorted(&arr)){
        cout<<"Array is sorted."<<endl;
    }
    else{
        cout<<"Array is not sorted."<<endl;
    }
}