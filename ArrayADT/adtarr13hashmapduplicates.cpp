#include<iostream>
#include<unordered_map>
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

    unordered_map<int,int> counts;
    cout<<"Duplicate elements are :";
    for(int i=0;i<arr.length;i++){
        counts[arr.A[i]]++;
    }

    for(auto c : counts){
        if(c.second >1){
            cout<<c.first<<" repeated "<<c.second<<" times"<<endl;
        }
    }
    return 0;
}