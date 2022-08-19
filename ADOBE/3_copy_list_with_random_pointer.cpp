#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* random;

    node(int data){
        this->data = data;
        next = NULL;
        random = NULL;
    }
};

node* copyrandompointer(node* head){
    node* l1 , *l2 , *newhead;
    if (head == NULL)
    {
        return NULL;
    }
    for (l1 = head; l1 != NULL; l1 = l1->next->next)
    {
        l2 = new node(l1->data);
        l2->next = l1->next;
        l1->next = l2;
    }
    newhead = head->next;
    for(l1 = head; l1 != NULL; l1 = l1->next->next){
        if (l1->random != NULL)
        {
            l1->next->random = l1->random->next;
        }
    }
    for (l1 = head; l1 != NULL; l1 = l1->next)
    {
        l2 = l1->next;
        l1->next = l2->next;
        if (l2->next != NULL)
        {
            l2->next = l2->next->next;
        }
    }
    return newhead;
}

int main(){

}