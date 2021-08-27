#include<iostream>
using namespace std;

class treenode{
    public:
    int data;
    treenode* left;
    treenode* right;

    treenode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~treenode(){
        delete left;
        delete right;
    }
};

void Binarytree2dll(treenode* root , treenode** head){
    if (root == NULL)
    {
        return;
    }
    
    static treenode* prev = NULL;

    Binarytree2dll(root->left , head);
    if (prev == NULL)
    {
        *head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    Binarytree2dll(root->right , head);
}

void printList(treenode *node)
{
    while (node!=NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}

int main(){
    treenode *root    = new treenode(10);
    root->left        = new treenode(12);
    root->right       = new treenode(15);
    root->left->left  = new treenode(25);
    root->left->right = new treenode(30);
    root->right->left = new treenode(36);
 
    treenode *head = NULL;
    Binarytree2dll(root, &head);
    printList(head);
}