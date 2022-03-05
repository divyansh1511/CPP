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

void print(node* head){
    node* curr = head;
    while (curr != NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

node* getintersection(node* head1 , node* head2){
    int m , n;
    m = n = 0;
    node* curr1 = head1;
    node* curr2 = head2;
    while (curr1 != NULL)
    {
        m++;
        curr1 = curr1->next;
    }
    while (curr2 != NULL)
    {
        n++;
        curr2 = curr2->next;
    }
    curr1 = head1;
    curr2 = head2;
    if (m > n)
    {
        for (int i = 0; i < m-n; i++)
        {
            curr1 = curr1->next;
        }
    }
    else
    {
        for (int i = 0; i < n-m; i++)
        {
            curr2 = curr2->next;
        }
    }
    while (curr1 != NULL)
    {
        if (curr1 == curr2)
        {
            return curr1;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return NULL;
}

int main(){

}