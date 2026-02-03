#include<iostream>
using namespace std;

struct Queue{
    int *Q;
    int front;
    int rear;
    int size;
};

void enqueue(Queue *q,int val){
    if(q->rear == q->size-1){
        cout<<"Queue already full!";
        return;
    }
    q->rear++;
    q->Q[q->rear] = val;
 
}

int dequeue(Queue *q){
    int x=-1;
    if(q->front == q->rear){
        cout<<"Queue is empty.";
    }
    else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;

}

void displayQueue(Queue *q){
    if(q->front == q->rear){
        cout << "Queue is empty\n";
        return;
    }
    for(int i = q->front + 1; i <= q->rear; i++){
        cout << q->Q[i] << " ";
    }
    cout << endl;
}

bool isEmpty(Queue *q){
    if(q->rear==q->front){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(Queue *q){
    if(q->rear == q->size-1){
        return true;
    }
    else{
        return false;
    }
}

int firstElem(Queue *q){
    if(q->front != q->rear){
        return q->Q[q->front + 1];
    }
    return -1;
}


int lastElem(Queue *q){
    if(q->rear >= 0){
        return q->Q[q->rear];
    }
    return -1;
}

int main(){
    struct Queue q;
    int n,val;
    cout<<"Size of queue ?";
    cin>>q.size;
    q.Q = new int[q.size];
    q.front = -1;
    q.rear = -1;

    cout<<"how many elems currentl ?";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Element "<<i<<" ";
        cin>>val;
        enqueue(&q,val);
    }

    displayQueue(&q);

    cout<<"Dequeuing... ";
    dequeue(&q);
    displayQueue(&q);

    isFull(&q)? cout<<"Queue is full no more elems to be added "<<endl : cout<<"Queue not full"<<endl;

    isEmpty(&q)? cout<<"Queue is empty"<<endl : cout<<"Queue is not empty"<<endl;

    int x = firstElem(&q);
    int y = lastElem(&q);

    if(x!=-1){ cout<<"First elem is "<<x<<endl; }
    if(y!=-1){cout<<"Last elemet is "<<y<<endl; }
    return 0;
}