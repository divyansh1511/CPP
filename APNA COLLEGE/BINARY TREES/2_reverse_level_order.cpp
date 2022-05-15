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

vector<vector<int>> reverselevelorder(treenode* root){
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);
    vector<vector<int>> ans;
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            treenode* currnode = pendingnodes.front();
            pendingnodes.pop();
            v.push_back(currnode->data);
            if (currnode->left != NULL)
            {
                pendingnodes.push(currnode->left);
            }
            if (currnode->right != NULL)
            {
                pendingnodes.push(currnode->right);
            }
        }
        ans.push_back(v);
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

int main(){

}