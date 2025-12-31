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

void reverseArray(struct Array *arr){
    struct Array revArr;
    revArr.size = arr->size;
    revArr.length = arr->length;
    revArr.A = new int [revArr.size];
    int i=0,j=0;
    for(int i=arr->length-1;i>=0;i--){
        revArr.A[j] = arr->A[i];
        j++;
    }
    cout<<"Reversed array is :";
    display(&revArr);
}
int main(){
    struct Array arr;
    cout<<"Enter size of array: ";
    cin>>arr.size;
    arr.A = new int [arr.size];

    cout<<"How many elements currently? :";
    cin>>arr.length;    
    cout<<"Enter elements :";
    for(int i=0;i<arr.length;i++){
        cin>>arr.A[i];
    }
    display(&arr);
    reverseArray(&arr);
    return 0;
}