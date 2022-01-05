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

node* add2num(node* l1 , node* l2){
    node*  t1 = l1 ;
    node*  t2 = l2 ;
    node*  t3 = NULL ;
    node* pre = NULL ;
    int sum = 0     ;
    int carry = 0   ;
    int num1 = 0 ;
    int num2 = 0 ;
    while( t1 != NULL || t2 != NULL || carry >0)
    {
        //t3 = new ListNode();
        
        if(t1 != NULL)
        {
            num1 = t1->data ;
            t1 = t1->next ;
        }
        if(t2 != NULL)
        {
            num2 = t2->data ;
            t2 = t2->next ;
        }
        
        sum = carry + num1 + num2 ;
        carry = sum/10 ;
        node* l3 = new node(0);
        l3->data = sum%10 ;
        l3->next = NULL ;
        num1 = num2 = 0 ;
        if(t3 == NULL )
            t3 = l3 ;
        else
            pre->next = l3 ;
        pre = l3 ;
    
    }
    
    return t3;
}

void print(node* head){
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    node* head1 = takeinput();
    node* head2 = takeinput();
    node* ans = add2num(head1 , head2);
    print(ans);
}