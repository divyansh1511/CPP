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

node* merge2list(node* head1 , node* head2){
    node* newnode = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->next->data < head2->next->data)
    {
        newnode = head1;
        newnode->next = merge2list(head1->next , head2);
    }
    else
    {
        newnode = head2;
        newnode->next = merge2list(head1 , head2->next);
    }
    return newnode;
}

int main(){

}