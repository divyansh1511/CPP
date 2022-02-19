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
        else{
            tail->next = newnode;
            tail = newnode;
        }
        cin>>data;
    }
    return head;
}

void print(node* head){
    node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

node* sortbinary(node* head){
    node* odd = new node(9);
    node* even = new node(8);
    node* e2 = even;
    node* temp = odd;
    while (head != NULL)
    {
        if (head->data == 1)
        {
            odd->next = head;
            odd = odd->next;
        }
        else
        {
            even->next = head;
            even = even->next;
        }
        head = head->next;
    }
    even->next = temp->next;
    odd->next = NULL;
    return e2->next;
}

int main(){
    node* head = takeinput();
    print(head);
    head = sortbinary(head);
    print(head);
}