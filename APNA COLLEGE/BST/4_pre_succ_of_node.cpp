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

void pred_succ(treenode* root , int key){
    if (root == NULL)
    {
        return;
    }
    if (root->data == key)
    {
        if (root->left != NULL)
        {
            treenode* tmp = root->left;
            while (tmp->right)
            {
                tmp = tmp->right;
            }
            cout<<tmp->data<<endl;
        }
        if (root->right != NULL)
        {
            treenode* tmp = root->right;
            while (tmp->left)
            {
                tmp = tmp->left;
            }
            cout<<tmp->data<<endl;
        }
    }
}

int main(){

}