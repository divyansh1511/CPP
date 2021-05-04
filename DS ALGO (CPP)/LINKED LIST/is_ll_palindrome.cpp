#include<iostream>
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

node* reve(node* head){
    node* prev = NULL;
    node* curr = head;
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

node* middle(node* head){
    node* slow = head;
    node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool isPalindrome(node* head) {
        if(head==NULL || head->next==NULL){
            return true;
        } 
       node *List1,*List2,*temp;
       temp = middle(head);
       List2 = temp->next;
       temp->next = NULL;
       List2 = reve(List2);
       List1 = head;

        while(List1!=NULL && List2!=NULL)
        {
            if(List1->data != List2->data)
            {
                return false;
            }
            List1 = List1->next;
            List2 = List2->next;
        }

        return true;
    }

int main(){
    node* head = takeinput();
    cout<<isPalindrome(head)<<endl;
}