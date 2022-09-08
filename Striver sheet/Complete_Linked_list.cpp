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

void print(node* head){
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

node* reve(node* head){
    node* curr = head;
    node* prev = NULL;
    node* temp = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

node* middlenode(node* head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge2list(node* head1 , node* head2){
    node* newnode = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    else if (head1->data < head2->data)
    {
        newnode = head1;
        newnode->next = merge2list(head1->next , head2);
    }
    else
    {
        newnode = head2;
        newnode->next = merge2list(head1 , head2->next);
    }
    return newnode;
}

node* removenthnodefromend(node* head , int n){
    node* slow = head;
    node* fast = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    node* tmp = slow->next;
    slow->next = tmp->next;
    return head;
}

node* add2number(node* head1 , node* head2){
    int carry = 0;
    node* newnode = new node(-1);
    node* ans = newnode;
    while (head1 != NULL || head2 != NULL)
    {
        int sum = carry;
        if (head1 != NULL)
        {
            sum += head1->data;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            sum += head2->data;
            head2 = head2->next;
        }
        node* t = new node(sum%10);
        carry = sum/10;
        newnode->next = t;
        newnode = t;
    }
    return ans;
}

node* deletenode(node* head , int k){
    if (k == 0)
    {
        node* newnode = head->next;
        head->next = NULL;
        delete head;
        return newnode;
    }
    node* newnode = head;
    while (k != 1)
    {
        newnode = newnode->next;
        k--;
    }
    newnode->next = newnode->next->next;
    return head;
}

node* IntersectionPoint(node* h1 , node* h2){
    int n = 0;
    int m = 0;
    node* tmp = h1;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        n++;
    }
    tmp = h2;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        m++;
    }
    if (n > m)
    {
        for(int i = 0; i < (n-m);i++){
            h1 = h1->next;
        }
    }
    else
    {
        for (int i = 0; i < (m-n); i++)
        {
            h2 = h2->next;
        }
    }
    while (h1 != NULL && h2 != NULL)
    {
        if(h1->next == h2->next){
            return h1->next;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return NULL;
}

bool detectcycle(node* head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

node* revekelements(node* head , int k){
    node* curr = head;
    node* temp = NULL;
    node* prev = NULL;
    int count = 0;
    while (curr != NULL && count<k)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }
    if (temp != NULL)
    {
        head->next = revekelements(temp , k);
    }
    return prev;
}

bool isPalindrome(node* head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* temp = slow->next;
    slow->next = NULL;
    temp = reve(temp);
    while (temp != NULL)
    {
        if (temp->data != head->data)
        {
            return false;
        }
        temp = temp->next;
        head = head->next;
    }
    return true;
}

node* findthestartnode(node* head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (fast == NULL || fast->next == NULL)
    {
        return NULL;
    }
    slow = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

//-------------Flatten a linked list : https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1 ------------//

node* rotatelist(node* head , int k){
    if (k == 0 || head == NULL)
    {
        return head;
    }
    int count = 0;
    node* tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        count++;
    }
    tmp->next = head;
    tmp = head;
    int t = count - (k%count);
    node* ans = NULL;
    while (t > 0)
    {
        if (t == 1)
        {
            ans = tmp;
        }
        t--;
        tmp = tmp->next;
    }
    ans->next = NULL;
    return tmp;
}

//-----------Copy list with random pointers : https://leetcode.com/problems/copy-list-with-random-pointer/ ----//



int main(){

}