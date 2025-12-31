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

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void reverseArr(struct Array *arr){
    int i=0;
    int j =arr->length-1;
    while(i<=j){
        swap(&arr->A[i],&arr->A[j]);
        i++;
        j--;
    }
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
    reverseArr(&arr);
    cout<<"Reversed array is :";
    display(&arr);
    return 0;
}

