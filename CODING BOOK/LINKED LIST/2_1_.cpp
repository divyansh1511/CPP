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

//1. can be done by O(n^2) ---- 

//2.-------by O(n)

node* removeaDupilcate(node* head){
    unordered_map<int , int> mp;
    node* prev = NULL;
    node* curr = head;
    while (curr != NULL)
    {
        if (mp[curr->data] == 1)
        {
            prev->next = curr->next;
            curr = curr->next;
            continue;
        }
        mp[curr->data] = 1;
        prev = curr;
        curr = curr->next;
    }
    return head;
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
    head = removeaDupilcate(head);
    print(head);
}