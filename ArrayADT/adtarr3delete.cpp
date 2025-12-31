#include<iostream>
using namespace std;

struct Array{
    int *A;
    int size;
    int length;
};

void display(struct Array *arr){
    cout<<"Elemments are :";
    for(int i=0;i<arr->length;i++){
        cout<<arr->A[i]<<" ";
    }
    cout<<endl;
}

void deleteElement(struct Array *arr,int index){
    if(index >=0 && index < arr->length){
        int x =arr->A[index];
        for(int i=index; i<arr->length;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        cout<<"Deleted element is: "<<x<<endl;
    }
}

int main(){
    struct Array arr;

    cout<<"Enter size of array: ";
    cin>>arr.size;

    arr.A = new int [arr.size];

    cout<<"How many elements do you want currently ? :";
    cin>>arr.length;

    cout<<"Enter elements of array ";
    for(int i=0;i<arr.length;i++){
        cin>>arr.A[i];
    }
    display(&arr);

    int index;
    cout<<"Enter the index of element to delete: ";
    cin>>index;
    deleteElement(&arr,index);
    display(&arr);

}

