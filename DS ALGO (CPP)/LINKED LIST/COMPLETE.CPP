#include<iostream>
#include<vector>
#include <bits/stdc++.h>
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

node* Insertele(node* head , int value , int position){
    node* newnode = new node(value);

    if (position == 0)
    {
        newnode->next = head;
        return newnode;
    }
    
    node* prevnode = head;

    while (position != 1)
    {
        prevnode = prevnode->next;
        position--;    
    }
    newnode->next = prevnode->next;
    prevnode->next = newnode;
    return head;
}

node* deletenode(node* head , int position){
    if (position == 0)
    {
        node* temp = head->next;
        delete head;
        return temp;
    }
    
    node* prevnode = head;
    while (position != 1)
    {
        prevnode = prevnode->next;
        position--;
    }
    node* temp = prevnode->next;
    prevnode->next = prevnode->next->next;
    delete temp;
    return head;
}

void print(node* head){
    while (head != NULL)
    {
        cout<<head->data<<endl;
        head = head->next;
    }
}

node* middleNo(node* head){
    if (head == NULL)
    {
        return NULL;
    }
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* reverseLL(node* head){
    node* prev = NULL;
    node* temp = NULL;
    node* curr = head;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

node* reverseKelements(node* head , int k){
    node* prev = NULL;
    node* curr = head;
    node* temp = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }
    
    if (temp != NULL)
    {
        head->next = reverseKelements(temp , k);
    }
    return prev;
}

/////-------------AMAZON-----------

node* solve(node* head){
    
    node* zd=new node(8);
    node* od=new node(9);

    node* crr=head,*z=zd,*o=od;
    while(crr!=0){
        if(crr->data==0){
            z->next=crr;
            z=z->next;
        }
        else if(crr->data==1){
            o->next=crr;
            o=o->next;
        }
        crr=crr->next;
    }
    z->next=od->next;
    o->next=NULL;
    return zd->next;
}

int nooftimes(node* head , int key){
    node* temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            count++;
            temp = temp->next;
        }
        temp = temp->next;
    }
    return count;
}

node* deletealternatenodes(node* head){
    node* temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return head;
}

node* removeloop(node* head , node* slow){
    while (1 == 1)
    {
        if (head->next == slow->next)
        {
            slow->next = NULL;
            break;
        }
        head = head->next;
        slow = slow->next;
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
            cout<<"LOOP FOUND"<<endl;
            removeloop(head , slow);
            return true;
        }
    }
    return false;
}

node* merge2sortedLL(node* head1 , node* head2){
    node* newnode = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    else if (head1->data > head2->data)
    {
        newnode = head2;
        newnode->next = merge2sortedLL(head1 , head2->next);
    }
    else
    {
        newnode = head1;
        newnode->next = merge2sortedLL(head1->next , head2);
    }
    return newnode;
}

node* sortLinkedlist(node* head){
    node* newnode = head;
    vector<int> temp;
    while (newnode != NULL)
    {
        temp.push_back(newnode->data);
        newnode = newnode->next;
    }
    sort(temp.begin() , temp.end());
    newnode = head;
    
    for (int i = 0; i < temp.size(); i++)
    {
        newnode->data = temp[i];
        newnode = newnode->next;
    }
    return head;
}

node* swappairs(node* head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    node* temp = head->next;
    head->next = swappairs(temp->next);
    temp->next = head;

    return temp;
}

int main(){
    node* head = takeinput();
    // head = Insertele(head , 100 , 0);
    // head = deletenode(head , 0);
    // print(head);
    // cout<<middleNo(head)->data<<endl;
    // cout<<endl;
    // head = reverseLL(head);
    // print(head);
    // cout<<endl;
    // head = reverseKelements(head , 3);
    // print(head);
    // cout<<nooftimes(head , 1)<<endl;
    // head = deletealternatenodes(head);
    // print(head);
    // node* head = new node(10);
    // head->next = new node(20);
    // head->next->next = new node(30);
    // head->next->next->next = head->next;

    // cout<<detectloop(head)<<endl;

    // node* head1 = takeinput();
    // node* head2 = takeinput();
    // node* head = merge2sortedLL(head1 , head2);

    // print(head);
    // head = sortLinkedlist(head);
    // print(head);
    // cout<<ispalindrome(head)<<endl;
    // head = swappairs(head);
    // print(head);

    head = solve(head);
    print(head);
}