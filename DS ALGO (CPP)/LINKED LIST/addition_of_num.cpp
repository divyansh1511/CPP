#include<iostream>
#include<cmath>
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

int countnum(node* head){
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int LLtonum(node* head){
    int count = countnum(head);
    int num = 1;
    for (int i = 0; i < count; i++)
    {
        num += head->data* pow(10 , i);
        head = head->next;
    }
    return num;
}

node* numToLL(int sum){
     node* mainHead = new node(sum);
     int remainder = sum % 10;
     mainHead->data = remainder;
     sum = sum / 10;
     node* head;
     head = mainHead;
     while (sum != 0){
         node* nextNode = new node(sum);
         int remainder = sum % 10;            
         nextNode->data = remainder;
         head->next = nextNode;
         head = nextNode;
         sum = sum / 10;
     }
     return mainHead;
}

int main(){
    node* head1 = takeinput();
    int a1 = LLtonum(head1);
    node* head2 = takeinput();
    int a2 = LLtonum(head2);
    int number = a1+a2;
    node* head = numToLL(number);
    print(head);
}