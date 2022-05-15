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

void rightview(treenode* root){
    if (root == NULL)
    {
        return;
    }
    queue<treenode*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            treenode* currnode = q.front();
            q.pop();
            if (i == n-1)
            {
                cout<<currnode->data<<" ";
            }
            if (currnode->left != NULL)
            {
                q.push(currnode->left);
            }
            if (currnode->right != NULL)
            {
                q.push(currnode->right);
            }
        }
    }
}

int main(){

}