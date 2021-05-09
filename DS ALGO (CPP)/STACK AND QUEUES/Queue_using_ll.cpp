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

class queueusingll{
    node* head;
    node* tail;
    int count;

    public:
    queueusingll(){
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

int main(){
    queueusingll q;
    int arr[] = {10,20,30,40,50};
    for (int i = 0; i < 5; i++)
    {
        q.enqueue(arr[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<q.dequeue()<<endl;
    }
}