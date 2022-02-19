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
        else{
            tail->next = newnode;
            tail = newnode;
        }
        head = head->next;
    }
    return head;
}

node* reverseLL(node* head){
    node* prev = NULL;
    node* temp = NULL;
    node* curr = head;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

node* merge(node* h1 , node* h2){
    node* a1 = h1;
    node* tmp1 = NULL;
    node* tmp2 = NULL;
    while(h2){
        tmp1=h1->next;
        h1->next=h2;
        h1=tmp1;
        tmp2=h2->next;
        h2->next=h1;
        h2=tmp2;            
    }
    return a1;
}

node* reoderlist(node* head){
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* temp = slow->next;
    slow->next = NULL;
    temp = reverseLL(temp);
    node* ans = merge(head , temp);
    return ans;
}

int main(){
    
}