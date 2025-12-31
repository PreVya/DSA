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

void append(struct Array *arr, int element){
    if(arr->length < arr->size){
        arr->A[arr->length] = element;
        arr->length++;
    }
}

void insert(struct Array *arr, int index, int element){
    if(index<=0 || index< arr->length){
        for(int i= arr->length;i>index;i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = element;
        arr->length++;
    }
    display(arr);
}

int main(){
    struct Array arr;
    cout<<"Enter size of array: ";
    cin>>arr.size;

    arr.A= new int [arr.size];
    
    cout<<"How many elements do you want currently ? :";
    cin>>arr.length;

    cout<<"Enter elements of array ";
    for (int i=0; i<arr.length;i++){
        cin>>arr.A[i];
    }

    display(&arr);

    int element1;
    cout<<"Enter element to append: ";
    cin>>element1;
    append(&arr,element1);
    display(&arr);

    int index,element2;
    cout<<"Enter the index at which you want to insert element: ";
    cin>>index;
    cout<<"Enter element to insert: ";
    cin>>element2;
    insert(&arr,index,element2); 
    
}