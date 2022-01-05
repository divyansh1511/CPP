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
//---------------------------------------BRUTE FORCE-----------------------------//
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

node* deletenthlast(node* head , int n){
    node* temp = reversell(head);
    if (n-1 == 0)
    {
        node* newnode = temp->next;
        delete temp;
        return newnode;
    }
    while (n-1 != 1)
    {
        temp = temp->next;
        n--;
    }
    node* curr = temp->next;
    temp->next = temp->next->next;
    delete curr;
    return reversell(temp);
}

//------------------------------------------OPTI---------------------------------//
node* deletenode(node* head , int k){
    node* temp;
    node* first = head;
    node* second = head;
    for (int i = 0; i < k; i++)
    {
        if (second->next == NULL)
        {
            if (i == k-1)
            {
                temp = head;
                head = head->next;
                free(temp);
            }
            return head;
        }
        second = second->next;
    }
    while (second->next != NULL)
    {
        first = first->next;
        second = second->next;
    }
    temp = first->next;
    first->next = first->next->next;
    free(temp);
    return head;
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
    head = deletenthlast(head , 2);
    print(head);
    head = deletenode(head , 2);
    print(head);
}