#include<iostream>
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
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

node* merge2sortedll(node* head1 , node* head2){
    node* newnode = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->data < head2->data)
    {
        newnode = head1;
        newnode->next = merge2sortedll(head1->next , head2);
    }
    if (head1->data > head2->data)
    {
        newnode = head2;
        newnode->next = merge2sortedll(head1 , head2->next);
    }
    return newnode;
}

int main(){
    node* head1 = takeinput();
    node* head2 = takeinput();

    node* result = merge2sortedll(head1 , head2);
    print(result);
}