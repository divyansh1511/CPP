#include<bits/stdc++.h>
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
    node* curr = head;
    while (curr != NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

node* partition(node* head , int k){
    node* beforestart = NULL;
    node* beforeend = NULL;
    node* afterstart = NULL;
    node* afterend = NULL;
    while (head != NULL)
    {
        if (head->data < k)
        {
            if (beforestart == NULL)
            {
                beforestart = head;
                beforeend = head;
            }
            else
            {
                beforeend->next = head;
                beforeend = head;
            }
        }
        else
        {
            if (afterstart == NULL)
            {
                afterstart = head;
                afterend = head;
            }
            else
            {
                afterend->next = head;
                afterend = head;
            }
        }
        head = head->next;
    }
    if (beforestart == NULL)
    {
        return afterstart;
    }
    beforeend->next = afterstart;
    return beforestart;
}

int main(){
    node* head = takeinput();
    print(head);
    head = partition(head , 5);
    print(head);
}