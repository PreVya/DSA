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
    for(int i=0;i<arr->length;i++){
        int count =1;
        if(arr->A[i]!=-1){
            for(int j=i+1;j<arr->length;j++){
                if(arr->A[i]==arr->A[j]){
                    count++;
                    arr->A[j]=-1;
                }
            }
            if(count >1){
                cout<<arr->A[i]<<" is repeated "<<count<<" times"<<endl;
            }
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

    cout<<"Enter elements (with duplicates) :";
    for(int i=0;i<arr.length;i++){
        cin>>arr.A[i];
    }

    display(&arr);
    cout<<"Duplicate elements are :";
    duplicates(&arr);
    return 0;
}