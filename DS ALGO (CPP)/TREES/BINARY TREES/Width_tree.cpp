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

treenode* takeinput(){
    queue<treenode*> pendingnodes;
    cout<<"enter root data "<<endl;
    int rootdata;
    cin>>rootdata;

    treenode* root = new treenode(rootdata);
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        treenode* currentnode = pendingnodes.front();
        pendingnodes.pop();

        cout<<"enter left child data of "<<currentnode->data<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if (leftchilddata != -1)
        {
            treenode* leftnode = new treenode(leftchilddata);
            currentnode->left = leftnode;
            pendingnodes.push(leftnode);
        }
        
        cout<<"enter right child data of "<<currentnode->data<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if (rightchilddata != -1)
        {
            treenode* rightnode = new treenode(rightchilddata);
            currentnode->right = rightnode;
            pendingnodes.push(rightnode);
        }
    }
    return root;
}

int nofonodesatK(treenode* root , int k){
    int count = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (k == 0)
    {
        return 1;
    }
    count = nofonodesatK(root->left , k-1) + nofonodesatK(root->right , k-1);
    return count;
}

int height(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return 1+max(height(root->left) , height(root->right));
}

int width(treenode* root){
    int heightoftree = height(root);
    int maxwidth = 0;

    for (int i = 0; i < heightoftree; i++)
    {
        int currentmaxwidth = nofonodesatK(root , i);
        if (currentmaxwidth > maxwidth)
        {
            maxwidth = currentmaxwidth;
        }
    }
    return maxwidth;
}

int main(){
    treenode* root = takeinput();
    cout<<width(root)<<endl;
}