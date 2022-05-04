#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

node *takeinput()
{
    node *head = NULL;
    node *tail = NULL;
    int data;
    cin >> data;
    while (data != -1)
    {
        node *newnode = new node(data);
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
        cin >> data;
    }
    return head;
}

node *removeele(node *head, int k)
{
    node *curr = head;
    node *prev = NULL;
    while (head)
    {
        if (head->data == k)
            head = head->next;
        else
            break;
    }
    curr = head;
    while (curr)
    {
        if (curr->data == k)
        {
            prev->next = curr->next;
        }
        else
            prev = curr;
        curr = curr->next;
    }
    return head;
}

int main()
{
    node *head = takeinput();
    removeele(head, 6);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}