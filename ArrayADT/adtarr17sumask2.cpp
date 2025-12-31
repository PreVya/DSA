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

//Finding pairs for given sum but in sorted array
int main(){
    struct Array arr;
    cout<<"Enter array size :";
    cin>>arr.size;

    arr.A = new int [arr.size];

    cout<<"How many elements currently? :";
    cin>>arr.length;

    cout<<"Enter elements in sorted manner :"<<endl;
    for(int i=0;i<arr.length;i++){
        cin>>arr.A[i];
    }

    display(&arr);

    int key;
    cout<<"Enter the sum value to find pairs :";
    cin>>key;

    int i=0;
    int j = arr.length -1;
    while(i<j){
        if(arr.A[i] +arr.A[j] == key){
            cout<<"Pair is :"<<arr.A[i]<<" and "<<arr.A[j]<<endl;
            i++;
            j--;
        }
        else if(arr.A[i] +arr.A[j] < key){
            i++;
        }
        else{
            j--;
        }
    }
    return 0;
}