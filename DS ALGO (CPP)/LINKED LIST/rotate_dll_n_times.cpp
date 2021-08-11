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

node* rotate(node* head, int N)
{
    if (N == 0)
        return head;
    node* current = head;

    int count = 1;
    while (count < N && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return head;

    struct node* NthNode = current;

    while (current->next != NULL)
        current = current->next;
    current->next = head;

    (head)->prev = current;

    head = NthNode->next;
 

    (head)->prev = NULL;
    NthNode->next = NULL;
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
    insertattail(head , 10);
    insertattail(head , 20);
    insertattail(head , 30);
    insertattail(head , 40);
    head = rotate(head , 2);
    print(head);
}