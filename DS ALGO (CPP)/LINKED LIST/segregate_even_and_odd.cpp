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

void print(node* head){
    while (head != NULL)
    {
        cout<<head->data<<endl;
        head = head->next;
    }
}

node* segregate(node* head){
    node* even = NULL;
    node* odd = NULL;
    node* evenend = NULL;
    node* oddend = NULL;

    while (head)
    {
        if (head->data%2 == 0)
        {
            if (even == NULL)
            {
                even = head;
                evenend = head;
            }
            else
            {
                evenend->next = head;
                evenend = evenend->next;
            }
        }
        else
        {
            if (odd == NULL)
            {
                odd = head;
                oddend = head;
            }
            else
            {
                oddend->next = head;
                oddend = oddend->next;
            }
        }
        head = head->next;
    }
    if (evenend)
    {
        evenend->next = odd;
    }
    if (oddend)
    {
        oddend->next = NULL;
    }
    if (even)
    {
        return even;
    }
    return odd;
}

int main(){
    node* head = takeinput();
    head = segregate(head);
    print(head);
}