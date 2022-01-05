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

int detectloop(node* head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        if (slow == fast)
        {
            cout<<"LOOP FOUND"<<endl;
            return slow->data;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return -1;
}

int main(){
    node* head = takeinput();
    cout<<detectloop(head)<<endl;
}