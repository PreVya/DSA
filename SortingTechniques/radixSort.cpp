#include<iostream>
using namespace std;

void displayArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countingSort(int arr[], int n, int exp) {
    int output[n];      // temporary array
    int count[10] = {0};  // digits 0-9

    // Count occurrences of digits
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Convert count[] to cumulative count[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (RIGHT to LEFT for stability)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);

    // Do counting sort for every digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
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
    radixSort(arr,n);
    cout<<"array after sorting :"<<endl;
    displayArray(arr,n);
    return 0;
}