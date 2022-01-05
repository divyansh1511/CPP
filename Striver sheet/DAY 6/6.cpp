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

node* merge(node* a , node* b){
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    node* result;
    if (a->data < b->data)
    {
        result = a;
        result->next = merge(a->next , b);
    }
    else
    {
        result = b;
        result->next = merge(a , b->next);
    }
    result->next = NULL;
    return result;
}

node* flatten(node* root){
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    return merge(root , flatten(root->next));
}

int main(){
    
}