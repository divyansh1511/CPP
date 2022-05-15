#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

node* reversell(node* head){
    node* temp = head;
    node* ne = NULL;
    while (temp)
    {
        ne = temp->next;
        temp->next = temp->prev;
        temp->prev = ne;
        head = temp;
        temp = temp->prev;
    }
    return head;
}

int main(){

}