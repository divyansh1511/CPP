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
    cout<<"enter root data"<<endl;
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

int height(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return 1+ max(height(root->left),height(root->right));
}

int diameter(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    
    int leftdiameter = diameter(root->left);
    int rightdiamter = diameter(root->right);

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return max(max(leftdiameter , rightdiamter) , 1+leftheight+rightheight);
}

int main(){
    treenode* root = takeinput();
    cout<<diameter(root)<<endl;
}