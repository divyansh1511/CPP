#include<bits/stdc++.h>
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

treenode* deletenode(treenode* root , int key){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        if (root->right == NULL)
        {
            treenode* ll = root->left;
            delete root;
            return ll;
        }
        else
        {
            treenode* tmp = root->right;
            while (tmp->left != NULL)
            {
                tmp = tmp->left;
            }
            swap(root->data , tmp->data);
        }
    }
    root->left = deletenode(root->left , key);
    root->right = deletenode(root->right , key);
    return root;
}

int main(){

}