#include <iostream>
#include<deque>

using namespace std;

void displayDequeue(const deque<int>& dq){
    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<" ";
    }
    cout<<endl;
}
int main(){
    deque<int> dq;

    int n,val;
    cout<<"How many elems in dq?";
    cin>>n;

    cout<<"Elemtns will be pushed from rear end "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Element "<<i<<" ";
        cin>>val;
        dq.push_back(val);
    }
    displayDequeue(dq);

    int newElem;
    cout<<"Enter new elemnt to enter from front end ";
    cin>>newElem;
    dq.push_front(newElem);
    displayDequeue(dq);

    cout<<"Enter new element to enter from rear end ";
    cin>>newElem;
    dq.push_back(newElem);
    displayDequeue(dq);

    cout<<"Dequeueing the front element ";
    dq.pop_front();
    displayDequeue(dq);

    cout<<"Dequeing the rear element ";
    dq.pop_back();
    displayDequeue(dq);

    dq.empty() == 1? cout<<"Deque is empty "<<endl : cout<<"Deque is not empty "<<endl;

    return 0;
}