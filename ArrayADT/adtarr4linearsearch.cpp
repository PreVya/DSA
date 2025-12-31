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

int linearSearch(struct Array *arr, int key){
    for(int i=0;i<arr->length;i++){
        if(arr->A[i] ==key){
            return i;
        }
    }
    return -1;
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

   int key;
   cout<<"Enter elemnt you want to search:";
   cin>>key;
   int index = linearSearch(&arr, key);
   if(index < 0){
        cout<<"Elemment not found"<<endl;
   }
   else{
    cout<<"Element at "<<index<<endl;
   }
}