// Given a sorted linked list:  2->2->2->5->6->6->8->8->9 . Output: 2 -> 5 -> 6 -> 8 -> 9

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

node* deleteduplicate(node* head){
    node* newnode = head;
    while (newnode->next != NULL)
    {
        if (newnode->data == newnode->next->data)
        {
            node* temp = newnode->next;
            newnode->next = newnode->next->next;
            delete temp;
        }
        else
        {
            newnode = newnode->next;
        }
    }
    return head;
}

int main(){
    node* head = takeinput();
    node* result = deleteduplicate(head);

    print(result);
}