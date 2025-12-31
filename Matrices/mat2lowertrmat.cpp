#include<iostream>
using namespace std;

class LTMatrix{
    private:
        int *A;
        int n;
    public:
        LTMatrix(int size){
            n= size;
            A= new int[n*(n+1)/2];
        }
        ~LTMatrix(){
            delete[] A;
        }

        void display(bool row=true);

        void setRowMajor(int i,int j, int x);
        int getRowMajor(int i, int j);

        void setColMajor(int i, int j, int x);
        int getColMajor(int i, int j);

        int getSize(){ return n;}
};

void LTMatrix :: setRowMajor(int i, int j, int x){
    if(i>=j){
        int index = (i*(i-1))/2  + (j-1);
        A[index] = x;
    }
}

int LTMatrix :: getRowMajor(int i,int j){
    if(i>=j){
        int index = (i*(i-1))/2  + (j-1);
        return A[index];
    }
    else{
        return 0;
    }
}

void LTMatrix :: setColMajor(int i, int j, int x){
    if(i>=j){
        int index = (n*(j-1) - (((j-1)*(j-2))/2)) + (i-j);
        A[index] = x;
    }
}

int LTMatrix :: getColMajor(int i, int j){
    if(i>=j){
        int index = (n*(j-1) - ((j-1)*(j-2))/2)  + (i-j);
        return A[index];
    }
    else{
        return 0;
    }
}

void LTMatrix :: display(bool row){
    for (int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            if(row){
                if(i>=j){
                    cout<<getRowMajor(i+1,j+1)<<" ";
                }
                else{
                    cout<<0<<" ";
                }
            }
            else{
                if(i>=j){
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
    cout<<"Enter nxn size for lower triangular matrix (both row major and col major): ";
    cin>>size;

    LTMatrix rm(size);
    cout<<"Enter elements for row major lower triangular matrix "<<endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i>=j){
                int elem;
                cout<<"Element at "<<i<<","<<j<<" ";
                cin>>elem;
                rm.setRowMajor(i+1,j+1,elem);
            }
        }
    }

    cout<<"The row major lower triangular matrix is "<<endl;
    rm.display(true);   

    LTMatrix cm(size);
    cout<<"Enter elements for column major lower triangular matrix "<<endl;
    for(int j=0;j<size;j++){ 
        for(int i=0;i<size;i++){ 
            if(i>=j){
                int elem;
                cout<<"Element at "<<i<<","<<j<<" ";
                cin>>elem;
                cm.setColMajor(i+1,j+1,elem);
            }
        }
    }

    cout<<"The column major lower triangular matrix is "<<endl;
    cm.display(false);  
    return 0;
}
