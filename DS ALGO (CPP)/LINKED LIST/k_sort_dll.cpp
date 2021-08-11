//not printing
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void insertathead(node* &head , int data){
    node* newnode = new node(data);
    
    newnode->next = head;
    if (head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
}

void insertattail(node* &head , int data){
    if (head == NULL)
    {
        insertathead(head , data);
        return;
    }
    
    node* newnode = new node(data);

    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newnode;
    newnode->prev = temp;
}

node* sorting(node* head , int k){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    for (node* i  = head->next ; i != NULL ; i = i->next)
    {
        node* j = i;
        while (j->prev == NULL && j->data < j->prev->data)
        {
            node* temp = j->prev->prev;
            node* temp2 = j->prev;
            node* temp3 = j->next;
            j->prev->next = temp3;
            j->prev->prev = j;
            j->prev = temp;
            j->next = temp2;
            if(temp != NULL)
                temp->next = j;
            if(temp3 != NULL)
                temp3->prev = temp2;
        }
        if(j->prev == NULL)
            head = j;
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

int main(){
    node* head = NULL;
    insertattail(head , 3);
    insertattail(head , 6);
    insertattail(head , 2);
    insertattail(head , 12);
    insertattail(head , 56);
    insertattail(head , 8);
    head = sorting(head , 2);
    print(head);
}