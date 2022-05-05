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

node* removeduplicate(node* head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node* tt = head;
    while (head->next != NULL && head->data == head->next->data)
    {
        head = head->next;
    }
    if (tt == head)
    {
        head->next = removeduplicate(head->next);
        return head;
    }
    else
    {
        head = head->next;
        return removeduplicate(head);
    }
}

int main(){

}