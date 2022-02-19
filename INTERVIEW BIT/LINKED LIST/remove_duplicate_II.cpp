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
        cin>>data;
    }
    return head;
}

void print(node* head){
    node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

node* removeDuplicate(node* head){
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    node* curr = head;
    while (curr != NULL && curr->data == curr->next->data)
    {
        head = head->next;
    }
    if (curr == head)
    {
        curr->next = removeDuplicate(curr->next);
        return curr;
    }
    else
    {
        head = head->next;
        return removeDuplicate(head);
    }
}

int main(){

}