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

int countno(node* tt){
    int count = 0;
    node* head = tt;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

int convert(node* head){
    int count = countno(head);
    int sum = 0;
    while (count != 0)
    {
        int h = head->data;
        sum += h*pow(2 , count-1);
        head = head->next;
        count--;
    }
    return sum;
}

int main(){

}