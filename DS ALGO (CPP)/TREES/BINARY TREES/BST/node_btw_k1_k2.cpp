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

void printbtwK1andK2(treenode* root , int k1 ,int k2){
    if (root == NULL)
    {
        return;
    }
    if (root->data > k1 && root->data < k2)
    {
        cout<<root->data<<" ";
    }
    if (root->data > k1)
    {
        printbtwK1andK2(root->left , k1 , k2);
    }
    if (root->data < k2)
    {
        printbtwK1andK2(root->right , k1 , k2);
    }
}

int main(){
    treenode* root = takeinput();
    printbtwK1andK2(root , 5 , 45);
}
// 40 20 60 10 30 50 70 -1 -1 -1 -1 -1 -1 -1 -1