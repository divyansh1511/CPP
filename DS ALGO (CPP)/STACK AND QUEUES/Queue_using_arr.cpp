#include<bits/stdc++.h>
using namespace std;

class queueUsingArr{
    int* data;
    int front;
    int rear;
    int capacity;
    
    public:
    queueUsingArr(){
        data = new int[20];
        front = 0;
        rear = 0;
        capacity = 20;
    }

    void Enqueue(int ele)
    {
        if (capacity == rear) {
            cout<<"Queue is full"<<endl;
            return;
        }
        else {
            data[rear] = ele;
            rear++;
        }
        return;
    }

    void queueDequeue()
    {
        if (front == rear) {
            cout<<"Queue is  empty"<<endl;
            return;
        }

        else {
            for (int i = 0; i < rear - 1; i++) {
                data[i] = data[i + 1];
            }
            rear--;
        }
        return;
    }
    
    void queueFront()
    {
        if (front == rear) {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<data[front]<<endl;
        return;
    }
};

int main(){

}