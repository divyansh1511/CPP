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

void zigzag(node* root){
    bool flag = true;
    node* curr = root;
    while (curr->next != NULL)
    {
        if (flag)
        {
            if (curr->data > curr->next->data)
            {
                swap(curr->data , curr->next->data);
            }
        }
        else
        {
            if (curr->data < curr->next->data)
            {
                swap(curr->data , curr->next->data);
            }
        }
        curr = curr->next;
        flag = !flag;
    }
}

int main(){

}