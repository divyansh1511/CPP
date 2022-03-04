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

node* kthfromend(node* head , int k){
    node* curr = head;
    for (int i = 0; i < k; i++)
    {
        curr = curr->next;
    }
    node* temp = head;
    while (curr != NULL)
    {
        temp = temp->next;
        curr = curr->next;
    }
    return temp;
}

void print(node* head){
    node* curr = head;
    while (curr != NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

int main(){
    node* head = takeinput();
    print(head);
    cout<<kthfromend(head , 3)->data<<endl;
}