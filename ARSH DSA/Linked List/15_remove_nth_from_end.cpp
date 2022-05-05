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

node* removenthfromend(node* head , int k){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && k != 0)
    {
        fast = fast->next;
        k--;
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main(){

}