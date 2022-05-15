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

node* oddevenlist(node* head){
    node* odd = new node(-1);
    node* even = new node(-1);
    node* e1 = even , *o1 = odd; 
    while (head != NULL)
    {
        if (head->data % 2 == 0)
        {
            even->next = head;
            even = even->next;
        }
        else
        {
            odd->next = head;
            odd = odd->next;
        }
        head = head->next;
    }
    even->next = o1;
    odd->next = NULL;
    return e1;
}

int main(){

}