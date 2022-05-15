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

node* reversell(node* head){
    node* curr = head;
    node* temp = NULL;
    node* prev = NULL;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

node* rearrange(node* head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* temp = slow->next;
    slow->next = NULL;
    temp = reversell(temp);
    node* newnode = new node(-1);
    node* tt = newnode;
    while (head || temp)
    {
        newnode->next = head;
        newnode = newnode->next;
        newnode->next = temp;
        newnode = newnode->next;
        head = head->next;
        temp = temp->next;
    }
    return tt;
}

int main(){

}