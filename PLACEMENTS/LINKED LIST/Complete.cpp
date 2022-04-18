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
    node* temp = head;
    while (!temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

node* reversell(node* head){
    node* temp = NULL;
    node* curr = head;
    node* prev = NULL;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

node* findmid(node* head){
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* mergesortedll(node* head1 , node* head2){
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
        newnode->next = mergesortedll(head1->next , head2);
    }
    else
    {
        newnode = head2;
        newnode->next = mergesortedll(head1 , head2->next);
    }
    return newnode;
}

node* removeNthfromend(node* head , int n){
    node* temp = head;
    node* pp = head;
    for (int i = 0; i < n; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return temp->next;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
        pp = pp->next;
    }
    pp->next = pp->next->next;
    return head;
}

node* addtwonumber(node* head1 , node* head2){
    node* l1 = head1;
    node* l2 = head2;
    node* l3 = NULL;
    node* pre = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int n1 = 0 , n2 = 0;
        if (l1 != NULL)
        {
            n1 = l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            n2 = l2->data;
            l2 = l2->next;
        }
        int sum = n1 + n2 + carry;
        carry = carry/10;
        node* newnode = new node(sum%10);
        if (l3 == NULL)
        {
            l3 = newnode;
            pre = newnode;
        }
        else
        {
            pre->next = newnode;
            pre = pre->next;
        }
    }
    return l3;
}

node* intersectionofll(node* head1 , node* head2){
    int n1 = 0 , n2 = 0;
    node* temp1 = head1;
    node* temp2 = head2;
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        n1++;
    }
    while (temp2 != NULL)
    {
        temp2 = temp2->next;
        n2++;
    }
    if (n1 > n2)
    {
        for (int i = 0; i < (n1-n2); i++)
        {
            head1 = head1->next;
        }
    }
    else
    {
        for (int i = 0; i < (n2-n1); i++)
        {
            head2 = head2->next;
        }
    }
    while (head1)
    {
        if (head1 == head2)
        {
            return head1;
        }
        head1 = head1->next;
        head2 = head1->next;
    }
    return NULL;
}

bool hascycle(node* head){
    node* slow = head;
    node* fast = head->next;
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

node* reversekele(node* root , int k){
    node* temp = NULL;
    node* curr = root;
    node* prev = NULL;
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
        root->next = reversekele(temp , k);
    }
    return prev;
}

bool isPalindrome(node* head){
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    node* t2 = slow->next;
    slow->next = NULL;
    t2 = reversell(t2);
    node* t1 = head;
    while (t2 != NULL)
    {
        if (t1->data != t2->data)
        {
            return false;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return true;
}

node* startcycle(node* head){
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
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

node* rotatecycle(node* head , int k){
    node* p = head;
    int count = 1;
    while (p->next)
    {
        p = p->next;
        count++;
    }
    p->next = head;
    p = p->next;
    int t = count - (k%count);
    node* q = NULL;
    while (t > 0)
    {
        if (t == 1)
        {
            q = p;
        }
        t--;
        p = p->next;
    }
    q->next = NULL;
    return p;
}

int main(){

}