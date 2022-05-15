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

int length(node* head){
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

node* intersectionPoint(node* head1 , node* head2){
    int n = length(head1);
    int m = length(head2);
    node* h1 = head1 , *h2 = head2;
    if (m > n)
    {
        for (int i = 0; i < m-n; i++)
        {
            h1 = h1->next;
        }
    }
    else
    {
        for (int i = 0; i < n-m; i++)
        {
            h2 = h2->next;
        }
    }
    while (h1)
    {
        if (h1 == h2)
        {
            return h1;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return NULL;
}

int main(){

}