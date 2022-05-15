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

void deletenodes(node* head){
    node* h1 = reverse(head);
    node* maxnode = head;
    node* temp , *currnode = head;
    while (currnode != NULL && currnode->next != NULL)
    {
        if (currnode->next->data < maxnode->data)
        {
            temp = currnode->next;
            currnode->next = temp;
        }
        else
        {
            currnode = currnode->next;
            maxnode = currnode;
        }
    }
}

int main(){

}