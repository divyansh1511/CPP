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

node* solve(node* head , int st , int lt){
    node* dummy = new node(0);
    node* prev = dummy;
    node* curr;
    for (int i = 0; i < st - 1; i++)
    {
        prev = prev->next;
    }
    curr = prev->next;
    for (int i = 0; i < lt - st; i++)
    {
        node* temp = prev->next;
        prev->next = curr->next;
        curr->next = curr->next->next;
        prev->next->next = temp;
    }
    return dummy->next;
}

int main(){
    node* head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    head->next->next->next->next = new node(50);
    node* root = solve(head , 1 , 3);
    while (root != NULL)
    {
        cout<<root->data<<" ";
        root = root->next;
    }
}