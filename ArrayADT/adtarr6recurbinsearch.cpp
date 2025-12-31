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

int recurBinSearch(int l, int h, int key, struct Array *arr){
    if(l<=h){
        int mid = (l+h)/2;
        if(key == arr->A[mid]){
            return mid;
        }
        else if (key < arr->A[mid]){
            return recurBinSearch(l, mid-1,key, arr);
        }
        else{
            return recurBinSearch(mid+1, h, key, arr);
        }
    }
    return -1;
}

int main(){
    struct Array arr;
    cout<<"Enter array size :";
    cin>>arr.size;

    cout<<"How many elments currently? :";
    cin>>arr.length;

    arr.A = new int[arr.size];

    cout<<"Enter all elements :";
    for(int i=0;i<arr.length;i++){
        cin>>arr.A[i];  
    }

    display(&arr);
    int key;
    cout<<"Enter element to search :";
    cin>>key;
    int index = recurBinSearch(0, arr.length -1, key, &arr);
    if(index != -1){
        cout<<"Element found at index :"<<index<<endl;
    }
    else{
        cout<<"Element not found !"<<endl;
    }
}

