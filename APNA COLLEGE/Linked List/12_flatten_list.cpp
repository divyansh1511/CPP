#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* child;
    node(int data){
        this->data = data;
        next = NULL;
        child = NULL;
    }
};

void flattenList(node* head){
    if (head == NULL)
    {
        return;
    }
    node* tmp;
    node* tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    node* curr = head;
    while (curr != tail)
    {
        if (curr->child)
        {
            tail->next = curr->child;

            tmp = curr->child;
            while (tmp->next)
            {
                tmp = tmp->next;
            }
            tail = tmp;
        }
        curr = curr->next;
    }
}

int main(){

}