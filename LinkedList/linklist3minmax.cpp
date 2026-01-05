#include<iostream>
#include<climits>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node *next;
};

vector<int> minMax(struct Node *p){
    int min=INT_MAX, max=INT_MIN;
    vector<int> ans;
    while(p!=nullptr){
        if(p->data > max){
            max = p->data;
        }
        if(p->data < min){
            min = p->data;
        }
        p=p->next;
    }
    ans.push_back(min);
    ans.push_back(max);
    return ans;
}

int main(){
    Node *head=nullptr, *tail=nullptr;
    int n,value;

    cout<<"Enter no. of lements in ll :";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"enter element "<<i<<" ";
        cin>>value;

        Node *newNode = new Node{value,nullptr};

        if(!head){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    cout<<"The list is  ";
    Node *temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

    vector<int> ans = minMax(head);
    cout<<"Minimum element : "<<ans[0]<<endl;
    cout<<"Maximum element :"<<ans[1]<<endl;
    return 0;

}

