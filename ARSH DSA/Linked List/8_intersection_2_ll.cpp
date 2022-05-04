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

node* intersection(node* head1 , node* head2){
    int n = 0 , m = 0;
    node* p1 = head1;
    node* p2 = head2;
    while (p1)
    {
        p1 = p1->next;
        n++;
    }
    while (p2)
    {
        p2 = p2->next;
        m++;
    }
    p1 = head1;
    p2 = head2;
    if (m > n)
    {
        for (int i = 0; i < m-n; i++)
        {
            p1 = p1->next;
        }
    }
    if (n > m)
    {
        for (int i = 0; i < n-m; i++)
        {
            p2 = p2->next;
        }
    }
    while (p1)
    {
        if (p1 == p2)
        {
            return p1;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return NULL;
}

int main(){

}