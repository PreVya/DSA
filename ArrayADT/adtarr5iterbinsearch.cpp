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

int binarySearch(struct Array *arr,int key){
    int l=0;
    int h=arr->length -1;

    while(l<=h){
        int mid = (l+h)/2;
        if(key == arr->A[mid]){
            return mid;        
        }
        else if(key<arr->A[mid]){
            h=mid -1;
        }
        else{
            l = mid +1;
        }
    }
    return -1;
}

int main(){
    struct Array arr;;
    cout<<"Enter size of array: ";
    cin>>arr.size;
    arr.A = new int[arr.size];
 

    cout<<"Enter current elemets you want :";
    cin>>arr.length;;

    cout<<"Enter all elements :";
    for(int i=0;i<arr.length;i++){
        cin>>arr.A[i];     
    }

    display(&arr);
    int key;
    cout<<"Enter element to search :";
    cin>>key;       
    int index = binarySearch(&arr,key);
    if(index != -1){
        cout<<"Element found at index :"<<index<<endl;
    }
    else{
        cout<<"Element not found "<<endl;
    }
}