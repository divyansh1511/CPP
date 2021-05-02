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

node* reversell(node* head){
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

node* addnumhelper(node* head , int num){
    node* output = head;
    node* prev = NULL;

    int carry = num;
    int sum = 0;
    while (head != NULL)
    {
        sum = head->data + carry;
        carry = sum/10;
        head->data = sum%10;
        prev = head;
        head = head->next;
    }
    while (carry > 0)
    {
        prev->next = new node(carry%10);
        prev = prev->next;
        carry = carry/10;
    }
    return output;
}

node* addnumber(node* head , int num){
    head = reversell(head);
    addnumhelper(head , num);
    return reversell(head);
}

int main(){
    node* head = takeinput();
    int num;
    cin>>num;

    node* result = addnumber(head , num);
    print(result); 
}