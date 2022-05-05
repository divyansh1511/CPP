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

node *reverseLL2(node *head, int m, int n)
{
    node *dummy = new node(0), *pre = dummy, *cur;
    dummy->next = head;
    for (int i = 0; i < m - 1; i++)
    {
        pre = pre->next;
    }
    cur = pre->next;
    for (int i = 0; i < n - m; i++)
    {
        node *temp = pre->next;
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = temp;
    }
    return dummy->next;
}

int main()
{
}