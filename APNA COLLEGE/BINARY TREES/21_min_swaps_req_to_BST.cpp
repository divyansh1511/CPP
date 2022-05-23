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

void inorder(treenode* root , vector<int> &v){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
}

int minswaps(treenode* root){
    vector<int> v;
    inorder(root , v);
    int n = v.size();
    vector<pair<int , int>> v1;
    for (int i = 0; i < n; i++)
    {
        v1[i].first = v[i];
        v1[i].second = i;
    }
    sort(v1.begin() , v1.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == v1[i].second)
        {
            continue;
        }
        else
        {
            swap(v1[i].first , v1[v1[i].second].first);
            swap(v1[i].second , v1[v1[i].second].second);
        }
        if (i != v1[i].second)
        {
            i--;
        }
        ans++;
    }
    return ans;
}

int main(){

}