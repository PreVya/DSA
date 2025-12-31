#include <iostream>
using namespace std;

class Matrix{
    private:
        int *A;
        int n;
    public:
        Matrix(int size){
            n = size;
            A = new int[n];
        }
        ~Matrix(){
            delete[] A;
        }
        void setDiagonalElems(int i, int j, int x){
            if(i == j){
                A[i] = x;
            }
        }
        int getElement(int i,int j){
            if(i==j){
                return A[i];
            }
            else{
                return 0;
            }
        }
        void displayMat(){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j){
                        cout<<A[i]<<" ";
                    }
                    else{
                        cout<<0<<" ";
                    }
                }
                cout<<endl;
            }
        }
};

int main(){
    int size;
    cout<<"Enter size for nxnx diagonal matrix: ";
    cin>>size;
    Matrix m(size);
    cout<<"Enter elements for diagonal matrix:"<<endl;
    for(int i=0;i<size;i++){
        int elem;
        cout<<"Element at"<<i<<","<<i<<" ";
        cin>>elem;
        m.setDiagonalElems(i,i,elem);
    }
    cout<<"The diagonal matrix is:"<<endl;
    m.displayMat();

    int getElemAt;
    cout<<"Enter index to get element at (i,i): ";
    cin>>getElemAt;
    cout<<"Elemet at index"<<getElemAt<<","<<getElemAt<<" is:"<<m.getElement(getElemAt,getElemAt)<<endl;
    return 0;

}