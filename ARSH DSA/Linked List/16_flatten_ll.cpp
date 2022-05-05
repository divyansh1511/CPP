#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node* child;
    node(int data){
        this->data = data;
        next = NULL;
        node* prev = NULL;
        node* child = NULL;
    }
};

node* flattenll(node* head){
    for (node* h = head; h;  h = h->next)
    {
        if (h->child)
        {
            node* temp = h->next;
            h->next = h->child;
            h->next->prev = h;
            h->child = NULL;
            node* p = h->next;
            while (p->next)
            {
                p = p->next;
            }
            p->next = temp;
            if (temp)
            {
                temp->prev = p;
            }
        }
    }
    return head;
}

int main(){

}