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

node* insertele(node* head , int val , int pos){
    node* curr = head;
    node* newnode = new node(val);
    if (pos == 0)
    {
        newnode->next = head;
        return newnode;
    }
    
    while (pos != 1)
    {
        curr = curr->next;
        pos--;
    }
    node* temp = curr->next;
    curr->next = newnode;
    newnode->next = temp;
    return head;
}

node* deletehead(node* head , int pos){
    if (pos == 0)
    {
        node* temp = head->next;
        delete head;
        return temp;
    }
    node* curr = head;
    while (pos != 1)
    {
        curr = curr->next;
        pos--;
    }
    node* temp = curr->next;
    curr->next = temp->next;
    temp->next = NULL;
    return head;
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

node* reversell(node* head){
    node* curr = head;
    node* temp = NULL;
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

node* reversekele(node* head , int k){
    node* curr = head;
    node* temp = NULL;
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
        head->next = reversekele(temp , k);
    }
    return prev;
}

void removeloop(node* &slow , node* &head){
    while (1 == 1)
    {
        if (slow->next == head->next)
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
    node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        if (slow == fast)
        {
            cout<<"LOOP FOUND"<<endl;
            removeloop(slow , head);
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

node* merge2sorted(node* head1 , node* head2){
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
        newnode->next = merge2sorted(head1->next , head2);
    }
    else
    {
        newnode = head2;
        newnode->next = merge2sorted(head1 , head2->next);
    }
    return newnode;
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

node* removekthfromend(node* head , int k){
    node* slow = head;
    node* fast = head;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}

node* removeDuplicate(node* head){
    unordered_map<int , int> mp;
    node* temp = head , *prev;
    while (temp != NULL)
    {
        mp[temp->data]++;
        if (mp[temp->data] > 1)
        {
            mp[temp->data]--;
            prev->next = temp->next;
        }
        else
        {
            prev = temp;
        }
        temp = temp->next;
    }
    return head;
}

node* helper(node* ff , node* ss){
    node* res = NULL;
    node* tmp = NULL;
    node* prev = NULL;
    int carry = 0 , sum = 0;
    while (!ff && !ss)
    {
        sum = carry + (ff ? ff->data : 0) + (ss ? ss->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum%10;
        tmp = new node(sum);
        if (res == NULL)
        {
            res = tmp;
        }
        else
        {
            prev->next = tmp;
        }
        prev = tmp;
        if (ff)
        {
            ff = ff->next;
        }
        if (ss)
        {
            ss = ss->next;
        }
    }
    if (carry > 0)
    {
        tmp->next = new node(carry);
    }
    return res;
}

node* add2numinll(node* head1 , node* head2){
    node* ff = reversell(head1);
    node* ss = reversell(head2);
    node* head = helper(ff , ss);
    head = reversell(head);
    return head;
}

int IntersectionPoint(node* head1 , node* head2){
    int count1 = 0 , count2 = 0;
    node* curr1 = head1 , *curr2 = head2;
    while (curr1 != NULL)
    {
        count1++;
        curr1 = curr1->next;
    }
    while (curr2 != NULL)
    {
        count2++;
        curr2 = curr2->next;
    }
    curr1 = head1;
    curr2 = head2;
    if (count1 > count2)
    {
        for (int i = 0; i < count1 - count2; i++)
        {
            curr1 = curr1->next;
        }
    }
    else
    {
        for (int i = 0; i < count2-count1; i++)
        {
            curr2 = curr2->next;
        }
    }
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1 == curr2)
        {
            return curr1->data;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;
}

node* mergesort(node* head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node* slow = head;
    node* fast = head;
    node* tmp = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        tmp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    tmp->next = NULL;
    mergesort(head);
    mergesort(slow);
    return merge2sorted(head , slow);
}

bool isPalindrome(node *head)
{
    
    if(head == NULL || head->next == NULL){
        return true;
    }
    node* slow = head;
    node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    node* tmp = slow->next;
    slow->next = NULL;
    tmp = reversell(tmp);
    while(tmp != NULL){
        if(head->data != tmp->data){
            return false;
        }
        head = head->next;
        tmp = tmp->next;
    }
    return true;
}

//---FLATTEN A LINKED LIST
//---CLONE A LINKED LIST WITH RANDOM POINTER

node* nodesgreatervalonright(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* prev = reversell(head);
    node*temp = prev;
    node* tt;
    node* curr = prev;
    while(curr != NULL && curr->next != NULL){
        if(curr->next->data < prev->data){
            tt = curr->next;
            curr->next = tt->next;
            delete tt;
        }
        else{
            curr = curr->next;
            prev = curr;
        }
    }
    node* a = reversell(temp);
    return a;
}

node* par(node* root , node* end){
    node* pivot = root , *newnode = root->next;
    while(newnode != end){
        if(newnode->data <= pivot->data){
            swap(newnode->data , pivot->data);
        }
        newnode = newnode->next;
    }
    return pivot;
}

void helper11(node* root , node* end){
    if(!root || !root->next || root == end){
        return;
    }
    node* mid = par(root , end);
    helper(root , mid);
    helper(mid->next , end);
}

void quickSort(struct node **headRef) {
    node* end = NULL;
    helper11(*headRef , end);
}

node* deleteDuplicates2(node* A) {
    if(A == NULL || A->next == NULL){
        return A;
    }
    node* temp = A;
    while(A->next != NULL && A->next->data == A->data){
        A = A->next;
    }
    if(temp == A){
        A->next = deleteDuplicates2(A->next);
        return A;
    }
    else{
        A = A->next;
        return deleteDuplicates2(A);
    }
}

node* rotatelist(node* head , int k){
    if (head == NULL || k == 0)
    {
        return head;
    }
    int count = 1;
    node* curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
        count++;
    }
    curr->next = head;
    curr = curr->next;
    int tt = count - (k%count);
    node* q = NULL;
    while (tt--)
    {
        if (tt == 1)
        {
            q = curr;
        }
        curr = curr->next;
    }
    q->next = NULL;
    return curr;
}

int main(){

}