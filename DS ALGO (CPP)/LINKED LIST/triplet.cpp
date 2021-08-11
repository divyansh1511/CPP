#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void insertathead(node* &head , int data){
    node* newnode = new node(data);
    newnode->next = head;
    if (head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
}

void insertattail(node* &head , int data){
    if (head == NULL)
    {
        insertathead(head , data);
        return;
    }
    node* newnode = new node(data);
    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

int countPairs(node* first , node* last , int k){
    node* head = first;
    node* tail = last;
    int count = 0;
    while (head->data < tail->data)
    {
        if (head->data + tail->data == k)
        {
            head = head->next;
            tail = tail->prev;
            count++;
        }
        if (head->data + tail->data < k)
        {
            head = head->next;
        }
        if (head->data + tail->data > k)
        {
            tail = tail->prev;
        }
    }
    return count;
}

int counttriplet(node* head , int k){
    if (head == NULL)
    {
        return 0;
    }
    node* current;
    node* first;
    node* last;
    last = head;
    int count = 0;
    while (last->next != NULL)
    {
        last = last->next;
    }
    for (current = head; current != NULL; current = current->next) {
        first = current->next;
        int a = countPairs(first, last, k - current->data);
        count += a;
    }
    return count;
}

int main(){
    node* head = NULL;
    insertattail(head, 9);
    insertattail(head, 8);
    insertattail(head, 6);
    insertattail(head, 5);
    insertattail(head, 4);
    insertattail(head, 2);
    insertattail(head, 1);
 
    int x = 17;
 
    cout << "Count = "<< counttriplet(head, x);
    return 0;
}