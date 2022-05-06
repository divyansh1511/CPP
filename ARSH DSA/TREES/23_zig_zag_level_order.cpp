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

vector<vector<int>> zigzaglevelorder(treenode* root){
    vector<vector<int>> ans;
    queue<treenode*> q;
    q.push(root);
    int f = 1;
    while (!q.empty())
    {
        vector<int> temp;
        int n = q.size();
        while (n--)
        {
            treenode* t = q.front();
            temp.push_back(t->data);
            q.pop();
            if (t->left != NULL)
            {
                q.push(t->left);
            }
            if (t->right != NULL)
            {
                q.push(t->right);
            }
        }
        if (f%2 == 0)
        {
            reverse(temp.begin() , temp.end());
        }
        ans.push_back(temp);
        f = !f;
    }
    return ans;
}

int main(){

}