#include<iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode(int val){
        this->val = val;
        next = NULL;
    }
};

//function to find the length of a linked list
     int findlength(ListNode *head){
        ListNode *temp = head;
        int c = 0;
        while(temp!=NULL){
            c++;
            temp = temp->next;
        }
        return c;
    }
    
    //Reccurssive function to add two numbers
    int add(ListNode *&first,ListNode *&second,int d){
        if(first==NULL&&second==NULL){
            return 0;
        }
        int ans = 0;
        if(d > 0){
            ans = first->val + add(first->next,second,d-1);
        }
        else{
            ans = first->val + second->val + add(first->next,second->next,d);
        }
        first->val = ans%10;
        return ans/10;
    }
    
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int ff = findlength(l1);
    int ss = findlength(l2);
    ListNode *first = NULL;
    ListNode *second = NULL;
    if(ff > ss){
        first = l1;
        second = l2;
    }
    else{
        first = l2;
        second = l1;
    }
    int d = abs(ff - ss);
        
    int ans = add(first,second,d);
    if(ans > 0){
        ListNode *nt = new ListNode(ans);
        nt->next = first;
        return nt;
    }
    return first;
}

void print(ListNode* head){
    while (head != NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
}

ListNode* takeinput(){
    ListNode* head = NULL;
    ListNode* tail = NULL;

    int data;
    cin>>data;
    while (data != -1)
    {
        ListNode* newnode = new ListNode(data);
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

int main(){
    ListNode* l1 = takeinput();
    ListNode* l2 = takeinput();

    ListNode* result = addTwoNumbers(l1 , l2);
    print(result); 
}