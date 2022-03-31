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

node* removeduplicates(node* head){
    if (head == NULL) return NULL;
    node* fakeHead = new node(0);
    fakeHead->next = head;
    node* pre = fakeHead;
    node* cur = head;
    while (cur != NULL) {
        while (cur->next != NULL && cur->data == cur->next->data) {
            cur = cur->next;
        }
        if (pre->next == cur) {
            pre = pre->next;
        } else {
            pre->next = cur->next;
        }
        cur = cur->next;
    }
    return fakeHead->next;
}

int main(){

}