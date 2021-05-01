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

node* takeinput(){
    node* head = NULL;
    node* tail = NULL;

    int data;
    cin>>data;
    while (data != -1)
    {
        node* newnode = new node(data);
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
        cin>>data;
    }
    return head;
}

int nooftimes(node* head , int value){
    node* newnode = head;
    int count = 0;
    while (newnode != NULL)
    {
        if (newnode->data == value)
        {
            count++;
        }
        newnode = newnode->next;
    }
    return count;
}

int main(){
    node* head = takeinput();
    cout<<nooftimes(head,1)<<endl;
}