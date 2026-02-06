#include<iostream>
using namespace std;

void displayArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int getMinIndex(int arr[],int s, int n){
    int minIndex =s;
    for(int i=minIndex+1;i<n;i++){
        if(arr[i]<arr[minIndex]){
            minIndex = i;
        }
    }
    return minIndex;
}
void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int index = getMinIndex(arr,i,n);
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
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
    selectionSort(arr,n);
    cout<<"array after sorting :"<<endl;
    displayArray(arr,n);
    return 0;
}