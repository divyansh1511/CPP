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

node* merge(node* t1 , node* t2){
    node* st = new node(-1);
    node* ptr = st;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            ptr->next = t1;
            t1 = t1->next;
        }
        else
        {
            ptr->next = t2;
            t2 = t2->next;
        }
        ptr = ptr->next;
    }
    
    if (t1 != NULL)
    {
        ptr->next = t1;
        t1 = t1->next;
    }
    if (t2 != NULL)
    {
        ptr->next = t2;
        t2 = t2->next;
    }
    return st->next;
}

node* mergesort(node* head){
    if (head == NULL)
    {
        return NULL;
    }
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* temp = slow->next;
    slow->next = NULL;
    node* t1 = mergesort(head);
    node* t2 = mergesort(temp);

    return merge(t1 , t2);
}

int main(){
    
}