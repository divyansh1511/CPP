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

node* reverse(node* h1){
    node* curr = h1;
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

node* add2num(node* head1 , node* head2){
    node* h1 = reverse(head1);
    node* h2 = reverse(head2);
    int carry = 0;
    node* newnode = new node(-1);
    node* ans = newnode;
    while (h1 || h2 || carry != 0)
    {
        int sum = (h1) ? h1->data : 0 + (h2) ? h2->data : 0 + carry;
        node* tt = new node(sum%10);
        carry = sum/10;
        newnode->next = tt;
        newnode = newnode->next;
    }
    return reverse(ans->next);
}

int main(){

}