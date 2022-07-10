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

int widthofBT(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    int res = 1;
    queue<pair<treenode* , int>> q;
    q.push({root , 0});
    while (!q.empty())
    {
        int n = q.size();
        int st = q.front().second;
        int end = q.back().second;
        res = max(res , end - st + 1);

        for (int i = 0; i < n; i++)
        {
            pair<treenode* , int> p = q.front();
            q.pop();
            int idx = p.second - st;

            if (p.first->left != NULL)
            {
                q.push({p.first->left , 2*idx + 1});
            }
            if (p.first->right != NULL)
            {
                q.push({p.first->right , 2*idx+2});
            }
        }
    }
    return res;
}

int main(){

}