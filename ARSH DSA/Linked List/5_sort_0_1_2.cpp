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

node* sort012(node* head){
    int count[] = {0 , 0 , 0};
    node* tt = head;
    while (tt)
    {
        int a = tt->data;
        count[a]++;
    }
    node* temp = head;
    int i = 0;
    while (temp)
    {
        if (count[i] == 0)
        {
            i++;
        }
        else
        {
            temp->data = i;
            --count[i];
            temp = temp->next;
        }
    }
    return head;
}

int main(){

}