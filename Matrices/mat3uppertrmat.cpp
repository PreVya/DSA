#include<iostream>
using namespace std;

class UTMatrix{
    private:
        int *A;
        int n;
    public:
        UTMatrix(int size){
            n = size;
            A = new int[n*(n+1)/2];
        }
        ~UTMatrix(){
            delete []A;
        }

        void display(bool row=true);

        void setRowMajor(int i,int j, int x);
        int getRowMajor(int i,int j);

        void setColMajor(int i, int j, int x);
        int getColMajor(int i,int j);

        int getSize(){ return n; }
};

void UTMatrix :: setRowMajor(int i, int j, int x){
    if(i<=j){
        int index = (n*(i-1) - ((i-2)*(i-1)/2)) + (j-i);
        A[index] = x;
    }
}

int UTMatrix :: getRowMajor(int i, int j){
    if(i<=j){
        int index = (n*(i-1) - ((i-2)*(i-1))/2) + (j-i);
        return A[index];
    }
    else{
        return 0;
    }
}

void UTMatrix :: setColMajor(int i, int j, int x){
    if(i<=j){
        int index = (j*(j-1)/2) + (i-1);
        A[index] = x;
    }
}

int UTMatrix :: getColMajor(int i, int j){
    if(i<=j){
        int index = (j*(j-1)/2) + (i-1);
        return A[index];
    }
    else{
        return 0;
    }
}

void UTMatrix :: display(bool row){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(row){
                if(i<=j){
                    cout<<getRowMajor(i+1,j+1)<<" ";
                }
                else{
                    cout<<0<<" ";
                }
            }
            else{
                if(i<=j){
                    cout<<getColMajor(i+1,j+1)<<" ";
                }
                else{
                    cout<<0<<" ";
                }
            }
        }
        cout<<endl;
    }
}

int main(){
    int size;
    cout<<"Enter size for upper triangular matrix nxn for both row and col major ";
    cin>>size;

    UTMatrix rm(size);
    cout<<"Enter elemets for row major ";
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i<=j){
                int elem;
                cout<<"Element "<<i<<","<<j<<" ";
                cin>>elem;
                rm.setRowMajor(i+1,j+1,elem);
            }
        }
    }
    cout<<"Elements in row major :"<<endl;
    rm.display();

    UTMatrix cm(size);
    cout<<"Enter elements for col major :";
    for(int j=0;j<size;j++){
        for(int i=0;i<size;i++){
            if(i<=j){
                int elem;
                cout<<"Element "<<i<<","<<j;
                cin>>elem;
                cm.setColMajor(i+1,j+1,elem);
            }
        }
    }
    cout<<"Element in column major "<<endl;
    cm.display(false);
}
