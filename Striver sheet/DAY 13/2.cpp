#include<iostream>
using namespace std;

class queueusingarr{
    public:
    int* data;
    int capacity;
    int front;
    int rear;
    queueusingarr(){
        data = new int[20];
        capacity = 20;
        front = -1;
        rear = -1;
    }
    int size(){
        return rear+1;
    }
    bool isempty(){
        return (front == -1) && (rear == -1);
    }
    void inqueue(int element){
        if (rear == capacity-1)
        {
            cout<<"overflow"<<endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = rear = 0;
            data[front] = element;
        }
        else
        {
            rear++;
            data[rear] = element;
        }
    }
    void dequeue(){
        if (front == -1 && rear == -1)
        {
            cout<<"queue is empty"<<endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            cout<<data[front]<<endl;
            front++;
        }
    }
};

int main(){
    
}