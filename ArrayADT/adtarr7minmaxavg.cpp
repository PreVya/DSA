#include<iostream>
using namespace std;

struct Array{
    int *A;
    int size;
    int length;
};

struct MinMax{
    int min;
    int max;
};

void display(struct Array *arr){
    cout<<"Elements are :";
    for(int i=0;i<arr->length;i++){
        cout<<arr->A[i]<<" ";
    }
    cout<<endl;
}   

int get(struct Array *arr,int index){
    if(index>=0 && index < arr->length){
        return arr->A[index];
    }
    return -1;
}

void set(struct Array *arr, int index, int x){
    if(index>=0 && index < arr->size){
        arr->A[index] = x;
    }
}

MinMax minandmax(struct Array *arr){
    struct MinMax m;
    m.max = arr->A[0];
    m.min = arr->A[0];

    for(int i=1; i<=arr->length -1 ;i++){
        if(arr->A[i]>m.max){
            m.max = arr->A[i];
        }
        else if(arr->A[i]<m.min){
            m.min = arr->A[i];
        }
    }
    return m;
}

int sum(struct Array *arr){
    int sum =0;
    for(int i=0;i<arr->length -1;i++){
        sum += arr->A[i];
    }
    return sum;
}

int avg(struct Array *arr){
    return sum(arr)/arr->length;
}

int main(){
    struct Array arr;

    cout<<"Enter size ";
    cin>>arr.size;

    arr.A = new int[arr.size];

    cout<<"Enter how many elements currently ? ";
    cin>>arr.length;

    cout<<"Enter all elements ";
    for(int i=0;i<arr.length;i++){      
        cin>>arr.A[i];
    }

    display(&arr);

    int index1, index2, key;

    cout<<"Enter index to get element";
    cin>>index1;
    cout<<"Element at index "<<index1<<" is "<<get(&arr,index1)<<endl;

    cout<<"Enter index and element to set element ";
    cin>>index2>>key;
    set(&arr,index2,key);
    display(&arr);

    struct MinMax m = minandmax(&arr);
    cout<<"Minimum is "<<m.min<<endl;
    cout<<"Maximum is "<<m.max<<endl;

    cout<<"Sum of elemnts in array is "<<sum(&arr)<<endl;
    cout<<"average of elemtns in array is "<<avg(&arr)<<endl;

    return 0;
}