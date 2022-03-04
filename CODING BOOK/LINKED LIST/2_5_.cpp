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

void print(node* head){
    node* curr = head;
    while (curr != NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

node* add2num(node* head1 , node* head2){
    node* head = NULL;
    node* tail = NULL;
    int carry = 0;
    int sum = 0;
    while (head1 != NULL || head2 != NULL || carry != 0)
    {
        int sum = ((head1 != NULL) ? head1->data : 0) + ((head2 != NULL) ? head2->data : 0)+carry;
        node* newnode = new node(sum%10);
        carry = sum/10;
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
        head1 = head1->next;
        head2 = head2->next;
    }
    return head;
}

int main(){
    node* head1 = takeinput();
    node* head2 = takeinput();
    node* head = add2num(head1 , head2);
    print(head);
}