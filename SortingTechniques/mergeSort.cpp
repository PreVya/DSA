#include<iostream>
using namespace std;

void displayArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr[],int p, int q, int r){
   int size = r -p +1;
   int ans[size];
   int i = p, j=q+1,k=0;

   while(i<=q && j<=r){
    if(arr[i]<arr[j]){
        ans[k] = arr[i];
        k++;
        i++;
    }
    else{
        ans[k] = arr[j];
        k++;
        j++;
    }
   }

   while(i<=q){
    ans[k] = arr[i];
    k++;
    i++;
   }

   while(j<=r){
    ans[k] = arr[j];
    k++;
    j++;
   }
   
   for(int x=0;x<size;x++){
    arr[p+x] = ans[x];
   }
}
void mergeSort(int arr[],int p, int r){
    int q;
    if(p<r){
        q = (p+r)/2;
        mergeSort(arr,p,q);
        mergeSort(arr,q+1,r);
        merge(arr,p,q,r);
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
    mergeSort(arr,0,n-1);
    cout<<"array after sorting :"<<endl;
    displayArray(arr,n);
    return 0;
}