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

node* removeloop(node* head , node* slow){
    while (1 == 1)
    {
        if (head->next == slow->next)
        {
            slow->next = NULL;
            break;
        }
        head = head->next;
        slow = slow->next;
    }
    
}

bool detectloop(node* head){
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout<<"LOOP FOUND"<<endl;
            removeloop(head , slow);
            return true;
        }
    }
    return false;
}

void print(node* head){
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    node* head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = head->next;

    cout<<detectloop(head)<<endl;
    print(head);
}