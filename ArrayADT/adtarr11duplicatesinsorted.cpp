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

void duplicates(struct Array *arr){
    int lastDuplicate = 0;

    for(int i=0;i<arr->length;i++){
        if(arr->A[i]==arr->A[i+1]&& arr->A[i]!=lastDuplicate){
            cout<<arr->A[i]<<" ";
            lastDuplicate = arr->A[i];
        }
    }
}
int main(){
    struct Array arr;
    cout<<"Enter array size ;";
    cin>>arr.size;
    arr.A = new int [arr.size];

    cout<<"How many elements currently? :";
    cin>>arr.length;    

    cout<<"Enter sorted elements (with duplicates) :";
    for(int i=0;i<arr.length;i++){
        cin>>arr.A[i];
    }

    display(&arr);

    cout<<"Duplicate elements are :";
    duplicates(&arr);
}
