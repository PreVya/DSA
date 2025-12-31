#include<iostream>
using namespace std;

class Array{
    private:
        int *A;
        int size;
        int length;
    public:
        Array(int sz){
            this->size = size;
            A= new int [size];
        }
        void create(){
            cout<<"Enter number of elements: ";
            cin>>length;
            cout<<"Enter all elements: ";
            for(int i=0;i<length;i++){
                cin>>A[i];
            }
        }
        void display(){
            cout<<"Elements are :";
            for(int i=0;i<length;i++){
                cout<<A[i]<<" ";   
            }
            cout<<endl;
        }
        ~Array(){
            delete []A;
            cout<<"Destructor called, memory freed."<<endl;
        }
};

int main(){
    Array arr1(10);
    arr1.create();
    arr1.display();
    return 0;
}