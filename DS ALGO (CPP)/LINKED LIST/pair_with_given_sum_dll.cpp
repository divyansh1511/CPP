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

int noofpairs(node* head , int k){
    node* temp = head;
    node* tail = head;
    int count = 0;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    while (head->data < tail->data)
    {
        if (head->data + tail->data == k)
        {
            head = head->next;
            tail = tail->prev;
            count++;
        }
        if (head->data + tail->data < k)
        {
            head = head->next;
        }
        if (head->data + tail->data > k)
        {
            tail = tail->prev;
        }
    }
    return count;
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
    insertattail(head , 1);
    insertattail(head , 2);
    insertattail(head , 4);
    insertattail(head , 5);
    insertattail(head , 6);
    insertattail(head , 8);
    insertattail(head , 9);
    cout<<noofpairs(head , 7)<<endl;
}