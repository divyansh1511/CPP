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

vector<int> rightview(treenode* root){
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode* currnode = pendingnodes.front();
            pendingnodes.pop();
            if (i == n-1)
            {
                v.push_back(currnode->data);
            }
            if (currnode->left != NULL)
            {
                pendingnodes.push(currnode->left);
            }
            if (currnode->right != NULL)
            {
                pendingnodes.push(currnode->right);
            }
        }
    }
    return v;
}

int main(){

}