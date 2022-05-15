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

void deletenode(node* root){
    node* prev;
    if (root == NULL)
    {
        return;
    }
    else
    {
        while (root->next)
        {
            root->data = root->next->data;
            prev = root;
            root = root->next;
        }
        prev->next = NULL;
    }
}

int main(){

}