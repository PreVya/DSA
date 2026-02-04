#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    int n,val;
    cout<<"Enter how many elems in pq :";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Elment "<<i<<" ";
        cin>>val;
        pq.push(val);
    }
     cout << "Size : "<<pq.size() << endl;
     
    cout << "Highest priority element"<<pq.top() << endl;  

    cout<<"Dequing an element -> the hight priority elem "<<endl;
    pq.pop();
    cout <<"Now highest prio elem is "<< pq.top() << endl;
   

    if (pq.empty())
        cout << "Empty\n";
    else
        cout << "Not empty\n";

    return 0;
}
