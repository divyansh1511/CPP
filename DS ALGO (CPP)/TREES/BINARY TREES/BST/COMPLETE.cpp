#include<iostream>
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

treenode* takeinput(){
    queue<treenode*> pendingnodes;
    cout<<"enter root data"<<endl;
    int rootdata;
    cin>>rootdata;

    treenode* root = new treenode(rootdata);
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        treenode* currnode = pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter left child data"<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if (leftchilddata != -1)
        {
            treenode* leftchild = new treenode(leftchilddata);
            currnode->left = leftchild;
            pendingnodes.push(leftchild);
        }
        
        cout<<"enter right child data"<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if (rightchilddata != -1)
        {
            treenode* rightchild = new treenode(rightchilddata);
            currnode->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}

bool isBST(treenode* root , int min , int max){
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }
    bool lefttree = isBST(root->left , min, root->data);
    bool righttree = isBST(root->right , root->data , max);

    return lefttree && righttree;
}

bool findnode(treenode* root , int k){
    if (root == NULL)
    {
        return false;
    }
    if (root->data == k)
    {
        return true;
    }
    if(root->data < k){
        return findnode(root->right , k);
    }
    else
    {
        return findnode(root->left , k);
    }
}

treenode* minnode(treenode* root){
    treenode* temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

treenode* maxnode(treenode* root){
    treenode* temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

void findPreSuc(treenode* root, treenode*& pre, treenode*& suc, int key)
{
    if (root == NULL)  return ;
    if (root->data == key)
    {
        if (root->left != NULL)
        {
            treenode* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
        if (root->right != NULL)
        {
            treenode* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
    if (root->data > key)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else 
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}

int LCAinBST(treenode* root , int n1 , int n2){
    if (root == NULL)
    {
        return 0;
    }
    if (root->data > n1 && root->data > n2)
    {
        LCAinBST(root->left , n1 , n2);
    }
    if (root->data < n1 && root->data < n2)
    {
        LCAinBST(root->right , n1 , n2);
    }
    return root->data;
}

treenode* inordersucc(treenode* root){
    treenode* temp = root->right;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

treenode* deletenode(treenode* root , int k){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > k)
    {
        root->left = deletenode(root->left , k);
    }
    else if (root->data < k)
    {
        root->right = deletenode(root->right , k);
    }
    else
    {
        if (root->right == NULL)
        {
            treenode* temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL)
        {
            treenode* temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            treenode* temp = inordersucc(root);
            swap(root->data , temp->data);
            root->right = deletenode(root , k);
        }
    }
}

void inorder(treenode* root , vector<int> &v){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
}

treenode* binarytoBST(vector<int> v , int start , int end){
    if (start > end)
    {
        return NULL;
    }
    int mid = (start+end)/2;
    treenode* root = new treenode(v[mid]);
    root->left = binarytoBST(v , start , mid-1);
    root->right = binarytoBST(v , mid+1 , end);
    return root;
}

treenode* convertbinarytoBST(treenode* root){
    vector<int> v;
    inorder(root,v);
    sort(v.begin() , v.end());
    binarytoBST(v , 0 , v.size() - 1);
}

treenode* deletenode(treenode* root , int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        if(root->right == NULL){
            treenode* temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            treenode* temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            swap(root->data , temp->data);
        }
    }
    root->left = deletenode(root->left , key);
    root->right = deletenode(root->right , key);
    return root;
}

int main(){
    treenode* root = takeinput();
    // cout<<isBST(root , INT_MIN , INT_MAX)<<endl;
    // cout<<findnode(root , 31)<<endl;
    // cout<<minnode(root)->data<<endl;
    // cout<<maxnode(root)->data<<endl;
    // treenode* prev = NULL;
    // treenode* suc = NULL;
    // findPreSuc(root , prev, suc , 3);
    // cout<<prev->data<<endl;
    // cout<<suc->data<<endl;
    // cout<<LCAinBST(root , 2 , 3)<<endl;
}

//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1