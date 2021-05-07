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

node* midele(node* head){
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* reve(node* head){
    node* prev = NULL;
    node* curr = head;
    node* temp = NULL;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

void reorder(node* head){
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    node* curr = midele(head);
    node* n1 = head;
    node* n2 = reve(curr);

    node* temp1;
    node* temp2;

    while (n2->next != NULL)
    {
        temp1 = n1->next;
        n1->next = n2;
        n1 = temp1;

        temp2 = n2->next;
        n2->next = n1;
        n2 = temp2;
    }
}

int main(){
    node* head = takeinput();
    reorder(head);
    print(head);
}