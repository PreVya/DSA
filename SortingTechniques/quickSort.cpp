#include<iostream>
using namespace std;

void displayArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int arr[],int low, int high){
   int pivot = arr[high];
   int i = low -1;
   for(int j=low;j<high;j++){
    if(arr[j]<pivot){
        i++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
   }
   int temp = arr[i+1];
   arr[i+1] = arr[high];
   arr[high] = temp;

   return i+1;

}
void quickSort(int arr[],int low, int high){
    if(low<high){
        int pi= partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
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
    quickSort(arr,0,n-1);
    cout<<"array after sorting :"<<endl;
    displayArray(arr,n);
    return 0;
}