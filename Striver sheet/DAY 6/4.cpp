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

node* reversell(node* head){
    node* temp = NULL;
    node* curr = head;
    node* prev = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

void print(node* head){
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

node* findmid(node* head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool ispalindrome(node* head){
    node* l1 = head;
    node* temp = findmid(head);
    node* l2 = temp->next;
    temp->next = NULL;
    l2 = reversell(l2);
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data != l2->data)
        {
            return false;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return true;
}

int main(){
    node* head = takeinput();
    cout<<ispalindrome(head)<<endl;
}