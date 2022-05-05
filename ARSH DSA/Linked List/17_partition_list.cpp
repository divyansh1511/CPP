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

node* partitionList(node* head , int k){
    node* h1 = NULL;
    node* t1 = NULL;
    node* h2 = NULL;
    node* t2 = NULL;
    while (head)
    {
        if (head->data <= k)
        {
            if (h1 == NULL)
            {
                h1 = head;
                t1 = head;
            }
            else
            {
                t1->next = head;
                t1 = head;
            }
        }
        else
        {
            if (h2 == NULL)
            {
                h2 = head;
                t2 = head;
            }
            else
            {
                t2->next = head;
                t2 = head;
            }
        }
        head = head->next;
    }
    if (t1 != NULL)
    {
        t1->next = h2;
    }
    return h1;
}

int main(){

}