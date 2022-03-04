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
    node* curr = head;
    while (curr != NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

bool palindrome(node* head){
    stack<int> st;
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        st.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast != NULL)
    {
        slow = slow->next;
    }
    while (slow != NULL)
    {
        int a = st.top();
        if (a != slow->data)
        {
            return false;
        }
        slow = slow->next;
    }
    return true;
}

int main(){

}