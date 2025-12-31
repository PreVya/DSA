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

//TC = O(n) and SC = O(n)
Array missElems(struct Array *arr){
    struct Array missing;
    missing.size = arr->size;
    missing.length =0;
    missing.A = new int[missing.size];

    int diff = arr->A[0] -0;

    for(int i=0;i<arr->length;i++){
        if(arr->A[i]- i !=diff){
            while(arr->A[i] - i > diff){
                missing.A[missing.length++] = i + diff;
                diff++;
            }
        }
    }
    return missing;
}


//TC = O(n) and SC = O(1)
void missElemsPrint(struct Array *arr){
    int diff = arr->A[0] -0;

    for(int i=0;i<arr->length;i++){
        if(arr->A[i]-i !=diff){
            while(diff < arr->A[i] -i){
                cout<< i + diff <<" ";
                diff++;
            }
        }
    }
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

    struct Array missing = missElems(&arr);
    if(missing.length >0){
        cout<<"Missing elements are :";
        for(int i=0;i<missing.length;i++){
            cout<<missing.A[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"No missing elements found !"<<endl;
    }

    cout<<"Using print function missing elements are :";
    missElemsPrint(&arr);
}