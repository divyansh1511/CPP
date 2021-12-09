//NOT COMPLETED ... SOME ERROR
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
            head =  newnode;
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

node* merge2ll(node* head1 , node* head2){
    node* newnode = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    else if (head1->data < head2->data)
    {
        newnode = head1;
        newnode->next = merge2ll(head1->next , head2);
    }
    else
    {
        newnode = head2;
        newnode->next = merge2ll(head1 , head2->next);
    }
    return newnode;
}

void findmid(node* head , node** first , node** second){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *first = slow;
    *second = slow->next;
    slow->next = NULL;
}

void mergesort(node** head){
    node* curr = *head;
    node* first;
    node* second;

    if (curr == NULL || curr->next == NULL)
    {
        return;
    }
    

    findmid(curr , &first , &second);
    // cout<<"1st"<<first->data<<" "<<second->data<<endl;
    mergesort(&first);
    mergesort(&second);
    cout<<"a"<<endl;
    merge2ll(first , second);
}

void print(node* head){
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    node* head = takeinput();
    mergesort(&head);
    print(head);
}