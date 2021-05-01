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
        cout<<head->data<<endl;
        head = head->next;
    }
}

node* insert(node* head , int value , int position){
    node* newnode = new node(value);
    if (position == 0)
    {
        newnode->next = head;
        return newnode;
    }
    node* prevnode = head;
    while (position != 1)
    {
        prevnode = prevnode->next;
        position--;
    }
    newnode->next = prevnode->next;
    prevnode->next = newnode;
    return head;
}

int main(){
    node* head = takeinput();
    print(head);
    node* ab = insert(head , 20 , 4);
    print(ab);
}