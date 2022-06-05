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

string converttostr(treenode* root){
    if (root == NULL)
    {
        return "";
    }
    string s = to_string(root->data);
    if (root->left)
    {
        s+= "(" + converttostr(root->left) + ")";
    }
    else if (root->right)
    {
        s += "()";
    }
    if (root->right)
    {
        s += "(" + converttostr(root->right) + ")";
    }
    return s;
}

int main(){

}