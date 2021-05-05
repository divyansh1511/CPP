#include<iostream>
#include <bits/stdc++.h>
#include<vector>
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

node* sortlist(node* head){
    vector<int> v;
    node* newhead = head;

    while (newhead != NULL)
    {
        v.push_back(newhead->data);
        newhead = newhead->next;
    }
    sort(v.begin() , v.end());
    newhead = head;
    for (int i = 0; i < v.size(); i++)
    {
        newhead->data = v[i];
        newhead = newhead->next;
    }
    return head;
}

int main(){
    node* head = takeinput();
    node* result = sortlist(head);
    print(result);
}