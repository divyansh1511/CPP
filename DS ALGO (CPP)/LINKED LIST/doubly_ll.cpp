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

void deleteathead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}

void deletenode(node* &head , int pos){

    if (pos == 1)
    {
        deleteathead(head);
        return;
    }
    
    node* temp = head;
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

void print(node* head){
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

void reversell(node* &head){
    node* temp = NULL;
    node* curr = head;

    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
    {
        head = temp->prev;
    }
    
}

int main(){
    node* head = NULL;
    insertattail(head , 10);
    insertattail(head , 20);
    insertattail(head , 30);
    insertattail(head , 40);
    reversell(head);
    print(head);
}