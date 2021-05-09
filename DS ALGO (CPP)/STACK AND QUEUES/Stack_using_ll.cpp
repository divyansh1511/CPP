#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    public:
    node(int data){
        this->data = data;
        next = NULL;
    }
};

class stackusingLL{
    node* head;
    int count;

    public:
    stackusingLL(){
        head = NULL;
        count = 0;
    }

    int size(){
        return count;
    }

    bool isempty(){
        return count == 0;
    }

    void push(int element){
        node* newhead = new node(element);
        newhead->next = head;
        head = newhead;
        count++;
    }

    int pop(){
        if (isempty())
        {
            cout<<"stack is empty"<<endl;
        }
        int returnvalue = head->data;
        head = head->next;
        count--;
        return returnvalue;
    }

    int top(){
        if (isempty())
        {
            cout<<"stack is empty"<<endl;
        }
        return head->data;
    }
};

int main(){
    stackusingLL s;
    int arr[] = {10,20,30,40,50};
    for (int i = 0; i < 5; i++)
    {
        s.push(arr[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<s.pop()<<endl;
    }
}