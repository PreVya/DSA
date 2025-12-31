#include<iostream>
using namespace std;

class TeoplitzMatrix{
    private:
        int *A;
        int *B;
        int n;
    public:
        TeoplitzMatrix(int size){
            n = size;
            A = new int[n];
            B = new int[n-1];
        }
        ~TeoplitzMatrix(){
            delete[] A;
            delete[] B;
        }

        void display();
        void setElement(int i, int j, int x);
        int getElement(int i, int j);
        int getSize(){ return n; }
};

void TeoplitzMatrix :: setElement(int i, int j, int x){
    if(i<=j){
        A[j-i] =x;
    }
    else{
        B[i-j-1] =x;
    }
}

int TeoplitzMatrix :: getElement(int i, int j){
    if(i<=j){
        if(i==0){
            return A[j-i];
        }
        else{
            return getElement(i-1,j-1);
        }
    }
    else{
        if(j==0){
            return B[i-j-1];
        }
        else{
            return getElement(i-1,j-1);
        }

    }
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
    cout<<"Enter size for teopliz matrix :";
    cin>>size;
    TeoplitzMatrix tm(size);
    cout<<"Enter elements for teopliz matrix:"<<endl;
    cout<<"Enter the row 1 elements"<<endl;
    int elem;
    for(int k=0; k<size; k++) { 
        cout << "Enter element for row 0 and column "<<k;
        cin >> elem; tm.setElement(0, k, elem); 
    }
    
    for(int l=1;l<size;l++){
        cout<<"Enter element for column 0 and row "<<l;
        cin>>elem;
        tm.setElement(l,0,elem);
    }
    cout<<"Teoplitz matrix is:"<<endl;
    tm.display();
    return 0;
}