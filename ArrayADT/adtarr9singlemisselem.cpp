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

int missElem(struct Array *arr){
    int diff = arr->A[0] -0;
    for(int i=0;i<arr->length;i++){
        if(arr->A[i] -i!= diff){
            return i+diff;
        }
    }
    return -1;
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

    int missing = missElem(&arr);
    if(missing != -1){
        cout<<"Missing element is :"<<missing<<endl;
    }
    else{
        cout<<"No missing element found !"<<endl;
    }
}