#include<iostream>
using namespace std;

void displayArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubbleSort(int arr[],int n){
    int i,j,temp;

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int val,n;

    cout<<"Enter how many elements in array ? ";
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cout<<"Element "<<i<<" ";
        cin>>val;
        arr[i] = val;
    }

    cout<<"Array before sorting :"<<endl;
    displayArray(arr,n);
    cout<<"Sorting array ..."<<endl;
    bubbleSort(arr,n);
    cout<<"array after sorting :"<<endl;
    displayArray(arr,n);
    return 0;
}