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

void removeloop(node* slow , node* head){
    while (1 == 1)
    {
        if (head->next == slow->next)
        {
            slow->next = NULL;
            break;
        }
        slow = slow->next;
        head = head->next;
    }
}

bool detectloop(node* head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            removeloop(slow , head);
            return true;
        }
    }
    return false;
}

int main(){

}