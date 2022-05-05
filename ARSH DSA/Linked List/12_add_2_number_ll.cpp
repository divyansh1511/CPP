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

int findlength(node* head){
    node* tt = head;
    int count = 0;
    while (tt != NULL)
    {
        tt = tt->next;
        count++;
    }
    return count;
}

int addhelper(node* first , node* second , int d){
    if (first == NULL && second == NULL)
    {
        return 0;
    }
    int ans = 0;
    if (d > 0)
    {
        ans = first->data + addhelper(first->next , second , d-1);
    }
    else
    {
        ans = first->data + second->data + addhelper(first->next , second->next , d);
    }
    first->data = ans%10;
    return ans/10;
}

node* add2num(node* head1 , node* head2){
    int ff = findlength(head1);
    int ss = findlength(head2);
    node* first = NULL;
    node* second = NULL;
    if (ff > ss)
    {
        first = head1;
        second = head2;
    }
    else
    {
        first = head2;
        second = head1;
    }
    int d = abs(ff - ss);
    int ans = addhelper(first , second , d);
    if (ans > 0)
    {
        node* nt = new node(ans);
        nt->next = first;
        return nt;
    }
    return first;
}

int main(){

}