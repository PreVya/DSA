#include<iostream>
using namespace std;

struct Queue{
    int *Q;
    int front;
    int rear;
    int size;
};

void enqueue(Queue *q, int val){
    if((q->rear + 1) % q->size == q->front){
        cout << "Queue is full\n";
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = val;
}

int dequeue(Queue *q){
    int x = -1;
    if(q->front == q->rear){
        cout << "Queue is empty\n";
        return -1;
    }
    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front];
    return x;
}

void displayQueue(Queue *q){
    if(q->front == q->rear){
        cout << "Queue is empty\n";
        return;
    }

    int i = (q->front + 1) % q->size;
    while(i != (q->rear + 1) % q->size){
        cout << q->Q[i] << " ";
        i = (i + 1) % q->size;
    }
    cout << endl;
}

bool isEmpty(Queue *q){
    return q->front == q->rear;
}

bool isFull(Queue *q){
    return (q->rear + 1) % q->size == q->front;
}

int firstElem(Queue *q){
    if(!isEmpty(q))
        return q->Q[(q->front + 1) % q->size];
    return -1;
}

int lastElem(Queue *q){
    if(!isEmpty(q))
        return q->Q[q->rear];
    return -1;
}

int main(){
    Queue q;
    int n, val;

    cout << "Size of queue ? ";
    cin >> q.size;

    q.Q = new int[q.size];
    q.front = 0;
    q.rear = 0;

    cout << "How many elements currently ? ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Element " << i << ": ";
        cin >> val;
        enqueue(&q, val);
    }

    displayQueue(&q);

    cout << "Dequeuing...\n";
    dequeue(&q);
    displayQueue(&q);

    isFull(&q) ? cout<<"Queue is full\n" : cout<<"Queue not full\n";
    isEmpty(&q) ? cout<<"Queue is empty\n" : cout<<"Queue not empty\n";

    cout << "First element: " << firstElem(&q) << endl;
    cout << "Last element: " << lastElem(&q) << endl;

    delete[] q.Q;
    return 0;
}