#include<iostream>
#include<queue>
#include<vector>
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

treenode* buildBST(int* arr , int beginindex , int endindex){
    if (beginindex > endindex)
    {
        return NULL;
    }
    int mid = (beginindex+endindex)/2;
    treenode* root = new treenode(arr[mid]);
    root->left = buildBST(arr , beginindex , mid-1);
    root->right = buildBST(arr , mid+1 , endindex);

    return root;
}

void printtree(treenode* root){
    queue<treenode*>pendingnodes;
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        treenode* currentnode = pendingnodes.front();
        pendingnodes.pop();
        string tobeprinted = to_string(currentnode->data)+":";

        if (root->left != NULL)
        {
            tobeprinted += "L:"+to_string(currentnode->left->data)+",";
            pendingnodes.push(currentnode->left);
        }
        else
        {
            tobeprinted += "L:-1";
        }
        
        if (root->right != NULL)
        {
            tobeprinted += "R:"+to_string(currentnode->right->data)+",";
            pendingnodes.push(currentnode->right);
        }
        else
        {
            tobeprinted += "R:-1";
        }
        cout<<tobeprinted<<endl;
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    treenode* root = buildBST(arr , 0 , 6);
    printtree(root);
}