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

node* removenthfromend(node* head , int n){
    node* slow = head;
    node* fast = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    node* prev = NULL;
    while (fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = slow->next;
    return head;
}

int main(){

}