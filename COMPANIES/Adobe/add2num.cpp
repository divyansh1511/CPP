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

node* add2num(node* head1 , node* head2){
    int sum = 0;
    int carry = 0;
    node* newnode = NULL;
    node* res = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        sum = (head1 ? head1->data : 0) + (head2 ? head2->data : 0) + carry;
        carry = sum/10;
        sum = sum%10;
        node* temp = new node(sum);
        if (newnode == NULL)
        {
            newnode = temp;
            res = newnode;
        }
        else
        {
            newnode->next = temp;
            newnode = temp;
        }
        if (head1 != NULL)
        {
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            head2 = head2->next;
        }
    }
    if (carry != 0)
    {
        newnode->next = new node(carry);
    }
    return res;
}

void print(node* head){
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    node* head1 = new node(9);
    head1->next = new node(9);
    head1->next->next = new node(9);
    node* head2 = new node(9);
    head2->next = new node(9);
    // head2->next->next = new node(9);
    node* head = add2num(head1 , head2);
    print(head);
}