//-------not completed
#include<iostream>
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

void findmiddle(node* head , node** first , node** second){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *first = head;
    *second = slow->next;
    slow->next = NULL;
}

node* merge(node* first , node* second){
    node* newnode = NULL;
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }
    if (first->data < second->data)
    {
        newnode = first;
        newnode->next = merge(first->next , second);
    }
    else
    {
        newnode = second;
        newnode->next = merge(first , second->next);
    }
    return newnode;
}

void mergesort(node** head){
    node* curr = *head;
    node* first;
    node* second;

    if (!curr & !curr->next)
    {
        return;
    }
    findmiddle(curr , &first , &second);
    mergesort(&first);
    mergesort(&second);
    *head = merge(first , second);
}

void print(node* head){
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){

    node* head = takeinput();
    mergesort(&head);
    print(head);
}