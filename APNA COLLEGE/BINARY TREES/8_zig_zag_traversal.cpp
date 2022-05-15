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

vector<vector<int>> zigzagTraversal(treenode* root){
    queue<treenode*> q;
    q.push(root);
    bool flag = false;
    vector<vector<int>> ans;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            treenode* currnode = q.front();
            q.pop();
            v.push_back(currnode->data);
            if (currnode->left != NULL)
            {
                q.push(currnode->left);
            }
            if (currnode->right != NULL)
            {
                q.push(currnode->right);
            }
        }
        if (flag)
        {
            reverse(v.begin() , v.end());
        }
        ans.push_back(v);
        flag = !flag;
    }
    return ans;
}

int main(){

}