#include<bits/stdc++.h>
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

int getcount(node* head){
    node* temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int helper(int d , node* head1 , node* head2){
    node* curr1 = head1;
    node* curr2 = head2;
    for (int i = 0; i < d; i++)
    {
        curr1 = curr1->next;
    }
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1 == curr2)
        {
            return curr1->data;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;
}

int getintersection(node* head1 , node* head2){
    int len1 = getcount(head1);
    int len2 = getcount(head2);
    if (len1 > len2)
    {
        int d = len1 - len2;
        return helper(d , head1 , head2);
    }
    else
    {
        int d =len2 - len1;
        return helper(d , head2 , head1);
    }
}

void print(node* head){
    node* curr = head;
    while (curr != NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

int main(){
    node* head1 = takeinput();
    node* head2 = takeinput();
    cout<<getintersection(head1 , head2)<<endl;
}