#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* right;
    node(int data){
        this->data = data;
        next = NULL;
        right = NULL;
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

node* flatten(node* root){
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    root->right = flatten(root->right);
    root = merge(root , root->right);
    return root;
}

int main(){

}