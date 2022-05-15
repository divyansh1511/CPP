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

node* merge2sortedlist(node* head1 , node* head2){
    node* newnode = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->data < head2->data)
    {
        newnode = head1;
        newnode->next = merge2sortedlist(head1->next , head2);
    }
    else
    {
        newnode = head2;
        newnode->next = merge2sortedlist(head1 , head2->next);
    }
    return newnode;
}

node* mergeksorted(vector<node*> v){
    if (v.empty())
    {
        return NULL;
    }
    while (v.size() > 1)
    {
        v.push_back(merge2sortedlist(v[0] , v[1]));
        v.erase(v.begin());
        v.erase(v.begin());
    }
    return v[0];
}

int main(){

}