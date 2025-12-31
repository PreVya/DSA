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
    struct Array A1;
    cout<<"Enter size of first array :";
    cin>>A1.size;
    A1.A = new int [A1.size]; 

    cout<<"How many elements currently? :";
    cin>>A1.length;    
    cout<<"Enter elements of first array :";
    for(int i=0;i<A1.length;i++){
        cin>>A1.A[i];
    }

    struct Array A2;
    cout<<"Enter size of second array :";
    cin>>A2.size;
    A2.A = new int [A2.size];       
    cout<<"How many elements currently? :";
    cin>>A2.length;    
    cout<<"Enter elements of second array :";
    for(int i=0;i<A2.length;i++){
        cin>>A2.A[i];
    }

    display(&A1);
    display(&A2);

    struct Array unionArr;
    unionArr.size = A1.length + A2.length;
    unionArr.length =0;
    unionArr.A = new int [unionArr.size];

    unordered_map<int,int> hashMap;

    for(int i=0;i<A1.length;i++){
        hashMap[A1.A[i]]++;
    }

    for(int i=0;i<A2.length;i++){
        hashMap[A2.A[i]]++;
    }

    cout<<"Union of two arrays is :";
    for(auto h:hashMap){
        cout<<h.first<<" ";
    }
    return 0;

}
