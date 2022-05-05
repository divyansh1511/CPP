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

node* takeinput(){
    node* head = NULL;
    node* tail = NULL;

    int data;
    cin>>data;
    while (data != -1)
    {
        node* newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin>>data;
    }
    return head;
}

node* add2no(node* head1 , node* head2){
    node* h1 = head1;
    node* h2 = head2;
    node* h3 = NULL;
    node* pre = NULL;
    int carry = 0;
    while (h1 != NULL || h2 != NULL || carry != 0)
    {
        int n1 = 0 , n2 = 0;
        if (h1 != NULL)
        {
            n1 = h1->data;
            h1 = h1->next;
        }
        if (h2 != NULL)
        {
            n2 = h2->data;
            h2 = h2->next;
        }
        int sum = n1 + n2 + carry;
        carry = sum/10;
        node* newnode = new node(sum%10);
        if (h3 == NULL)
        {
            h3 = newnode;
            pre = newnode;
        }
        else
        {
            h3->next = newnode;
            h3 = newnode;
        }
    }
    return pre;
}

int main(){

}