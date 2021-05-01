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

node* deleteitem(node* head , int position){
    if (position == 0)
    {
        node* temp = head->next;
        delete head;
        return temp;
    }
    node* prevnode = head;
    while (position != 1)
    {
        prevnode = prevnode->next;
        position--;
    }
    node* temp = prevnode->next;
    prevnode->next = prevnode->next->next;
    delete temp;
    return head;
}

int main(){
    node* head = takeinput();
    deleteitem(head , 4);
    print(head);
}