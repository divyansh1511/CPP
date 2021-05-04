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

void print(node* head){
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

node* rotate(node* head , int k){
    if (head == NULL && k==0)
    {
        return head;
    }
    int length = 0;
    node* tail = head;
    while (tail->next != NULL)
    {
        length++;
        tail = tail->next;
    }
    length++;
    tail->next = head;
    int rotatepoint = length - k % length;

    tail = head;
    while (rotatepoint-- > 1)
    {
        tail = tail->next;
    }
    head = tail->next;
    tail->next = NULL;
    return head;
}

int main(){
    node* head = takeinput();
    node* result = rotate(head , 4);
    print(result);
}