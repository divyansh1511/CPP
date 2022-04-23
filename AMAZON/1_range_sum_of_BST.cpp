//---------LEETCODE --> 938-----------------//

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

int rangeSum(treenode* root , int low , int high){
    if (root == NULL)
    {
        return 0;
    }
    int sum = 0;
    if (root->data >= low && root->data <= high)
    {
        sum += root->data;
        sum += rangeSum(root->left , low , high);
        sum += rangeSum(root->right , low , high);
    }
    if (root->data > high)
    {
        sum += rangeSum(root->left , low , high);
    }
    if (root->data < low)
    {
        sum += rangeSum(root->right , low , high);
    }
    return sum;
}

int main(){

}