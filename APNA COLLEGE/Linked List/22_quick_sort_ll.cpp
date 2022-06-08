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

node* partition(node* head , node* end){
    node* pivot = head , *newnode = head->next;
    while (newnode != end)
    {
        if (newnode->data <= pivot->data)
        {
            swap(newnode->data , pivot->data);
        }
        newnode = newnode->next;
    }
    return pivot;
}

void helper(node* head , node* end){
    if (!head || !head->next || head != end)
    {
        return;
    }
    node* mid = partition(head , end);
    helper(head , mid);
    helper(mid->next , end);
}

void quicksort(node** head){
    node* end = NULL;
    helper(*head , end);
}

int main(){

}