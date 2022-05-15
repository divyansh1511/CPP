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

node* merge(node* head1 , node* head2){
    node* newnode = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->data < head2->data)
    {
        newnode = head1;
        newnode->next = merge(head1->next , head2);
    }
    else
    {
        newnode = head2;
        newnode->next = merge(head1 , head2->next);
    }
    return newnode;
}

node* mergesort(node* head){
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL || fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* temp = slow->next;
    slow->next = NULL;
    mergesort(head);
    mergesort(temp);
    return merge(head , temp);
}

int main(){

}