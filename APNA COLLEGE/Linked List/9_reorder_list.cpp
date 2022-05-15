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

node* reverse(node* head){
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

node* merge2(node* head1 , node* head2){
    node* pp = head1;
    node* tmp1 = NULL;
    node* tmp2 = NULL;
    while (head2->next)
    {
        tmp1 = head1->next;
        head1->next = head2;
        head1 = tmp1;

        tmp2 = head2->next;
        head2->next = head1;
        head1 = tmp2;
    }
    return pp;
}

node* reorderlist(node* head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* mid = slow->next;
    slow->next = NULL;
    node* tt = reverse(mid);
    node* newnode = merge2(head , tt);
    return newnode;
}

int main(){

}