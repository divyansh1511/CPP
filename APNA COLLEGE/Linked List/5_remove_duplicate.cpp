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

node* removeduplicate(node* head){
    node* ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        node* ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr2->data == ptr2->next->data)
            {
                ptr2->next = ptr2->next->next;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    return head;
}

int main(){

}