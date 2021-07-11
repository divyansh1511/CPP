#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

class queuell{
    node* head;
    node* tail;
    int count;

    public:
    queuell(){
        head = NULL;
        tail = NULL;
        count = 0;
    }

    int size(){
        return count;
    }

    bool isempty(){
        return count == 0;
    }

    void enqueue(int element){
        node* newnode = new node(element);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        count++;
    }

    int dequeue(){
        if (isempty())
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        int returnvalue = head->data;
        head = head->next;
        count--;
        return returnvalue;
    }

    int front(){
        if (isempty())
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        return head->data;
    }
};

class stackusingqueue{
    queuell q1;
    queuell q2;

    public:
    int size(){
        return q1.size();
    }

    bool isempty(){
        return q1.size() == 0;
    }

    void push(int element){
        while (!q1.isempty())
        {
            q2.enqueue(q1.dequeue());
        }
        q1.enqueue(element);
        while (!q2.isempty())
        {
            q1.enqueue(q2.dequeue());
        }
    }

    int pop(){
        return q1.dequeue();
    }
};

int main(){
    stackusingqueue s;

    int arr[] = {10,20,30,40};
    for (int i = 0; i < 4; i++)
    {
        s.push(arr[i]);
    }
    while (!s.isempty())
    {
        cout<<s.pop()<<endl;
    }
}