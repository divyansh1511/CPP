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
        cout<<head->data<<" ";
        head = head->next;
    }
}

node* swapnodes(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* output = head->next;
    head->next = swapnodes(output->next);
    output->next = head;
        
    return output;
}

node* swap(node* prev, node* curr)
{
    prev->next = curr->next;
    curr->next = prev;
    return curr;
}

node* pairsSwap(node* head)
{
    //  Make a dummy node.
    node* dummy = new node(-1);

    dummy->next = head;

    node* curr = dummy;

    while (curr->next != NULL && curr->next->next != NULL)
    {
        curr->next = swap(curr->next, curr->next->next);
        curr = curr->next->next;
    }

    return dummy->next;
}

int main(){
    node* head = takeinput();
    head = swapnodes(head);
    // head = pairsSwap(head);
    print(head);
}