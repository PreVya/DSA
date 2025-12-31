#include<iostream>
using namespace std;

class TeoplitzMatrix{
    private:
        int *A;
        int n;
    public:
        TeoplitzMatrix(int size){
            n = size;
            A = new int[2*n-1];
        }
        ~TeoplitzMatrix(){
            delete[] A;
        }

        void display();
        void setElement(int i, int j, int x);
        int getElement(int i, int j);
        int getSize(){ return n; }
};

void TeoplitzMatrix :: setElement(int i, int j, int x){
    (i<=j)? A[(n-1) + (j-i)] = x : A[i-j-1] =x;
}

int TeoplitzMatrix :: getElement(int i, int j){
    return (i<=j)? A[(n-1) + (j-i)] : A[i-j-1];
}

void TeoplitzMatrix :: display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<getElement(i,j)<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int size;
    cout<<"Enter size for nxn teoplitz matrix: ";
    cin>>size;

    TeoplitzMatrix tz(size);
    cout<<"Enter the elemnts in column :";
    for(int k=1; k<size;k++){
        int elem;
        cout<<"Enter element "<<k<<","<<"0" ;
        cin>>elem;
        tz.setElement(k,0,elem);
    }
    cout<<"Enter elemets in row ";
    for(int l=0;l<size;l++){
        int elem;
        cout<<"Enter element 0,"<<l;
        cin>>elem;
        tz.setElement(0,l,elem);
    }
    cout<<"Teoplitz matrix is"<<endl;
    tz.display();
    return 0;
}
    

