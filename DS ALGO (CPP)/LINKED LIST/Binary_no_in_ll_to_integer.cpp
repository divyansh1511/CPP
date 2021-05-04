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

int countingnodes(node* head){
    int count = 0;
    if (head == NULL)
    {
        return 0;
    }
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int converting(node* head){
    int num = countingnodes(head);
    int sum = 0;

    while (num != 0)
    {
        int headdata = head->data;
        sum += headdata*pow(2 , num-1);
        head = head->next;
        num--;
    }
    return sum;
}

int main(){
    node* head = takeinput();
    cout<<converting(head)<<endl;
}