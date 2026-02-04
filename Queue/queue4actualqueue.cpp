#include<iostream>
#include<queue>

using namespace std;


int main(){
    queue<int> q;
    
    int n,val;
    cout<<"How many values in queue ?:";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Element "<<i<<" ";
        cin>>val;
        q.push(val);
    }
    cout<<"Size of queue "<<q.size()<<endl;
    
    cout<<"First elem before dequeuing "<<q.front()<<endl;
    cout<<"Dequeuing ..";
    q.pop();
    cout<<"First elem after dequeuing "<<q.front()<<endl;

    cout<<"Rear element before enquieing "<<q.back()<<endl;
    int newElem;
    cout<<"Enter new element to enqueue ";
    cin>>newElem;
    q.push(newElem);
    cout<<"Rear element after enquieing "<<q.back()<<endl;

    q.empty()==1? cout<<"Queue is empty"<<endl : cout<<"Queue is not empty"<<endl;
    return 0;
}