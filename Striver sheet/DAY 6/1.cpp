//--------------------------------INTERSECTION OF LL---------------------------------------//
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

int length(node* head){
    int count = 0;
    node* a = head;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int intersectnode(node* head1 , node* head2){
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    node* ptr1;
    node* ptr2;
    if (l1 > l2)
    {
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        d--;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

int main(){
    node* head1 = takeinput();
    node* head2 = takeinput();
    cout<<intersectnode(head1 , head2)<<endl;
}