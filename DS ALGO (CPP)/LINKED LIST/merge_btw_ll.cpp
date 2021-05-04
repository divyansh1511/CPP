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

node* mergell(node* head1 , int a , int b , node* head2){
    node* A = head1;
    node* B = head1;
    node* C = head2;

    while (C->next != NULL)
    {
        C = C->next;
    }
    a-=1;
    while (a>0)
    {
        A = A->next;
        a--;
    }
    b+=1;
    while (b>0)
    {
        B = B->next;
        b--;
    }
    A->next = head2;
    C->next = B;
    return head1;
}

int main(){
    node* head1 = takeinput();
    node* head2 = takeinput();

    node* result = mergell(head1 , 3,4,head2);
    print(result);
}