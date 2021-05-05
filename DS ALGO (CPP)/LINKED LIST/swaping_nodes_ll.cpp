#include<iostream>
#include<vector>
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

node* swaping(node* head , int k){
vector<node*> v;
    if(head == NULL)
        return head;
    node* temp = head;
    while(temp!=NULL)
    {
        v.push_back(temp);
        temp = temp->next;
    }
    swap(v[k-1]->data , v[v.size() - k]->data);
    return head;
}

int main(){
    node* head = takeinput();
    swaping(head , 2);
    print(head);
}