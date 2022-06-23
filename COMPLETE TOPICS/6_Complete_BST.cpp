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
            pendingnodes.push(leftchild);
            currnode->left = leftchild;
        }
        cout<<"enter right child data"<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if (rightchilddata != -1)
        {
            treenode* rightchild = new treenode(rightchilddata);
            pendingnodes.push(rightchild);
            currnode->right = rightchild;
        }
    }
    return root;
}

bool isBST(treenode* root , int mini , int maxi){
    if (root == NULL)
    {
        return true;
    }
    if (root->data < mini || root->data > maxi)
    {
        return false;
    }
    return isBST(root->left , mini , root->data) && isBST(root->right , root->data , maxi);
}

bool findNode(treenode* root , int key){
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (root->data > key)
    {
        return findNode(root->left , key);
    }
    return findNode(root->right , key);
}

treenode* deletenode(treenode* root , int key){
    if (root == NULL)
    {
        return root;
    }
    if (root->data == key)
    {
        if (root->right == NULL)
        {
            treenode* tmp = root->left;
            delete root;
            return tmp;
        }
        else
        {
            treenode* tmp = root->right;
            while (tmp->left != NULL)
            {
                tmp = tmp->left;
            }
            swap(root->data , tmp->data);
            root->right = deletenode(root->right , key);
            return root;
        }
    }
    if (root->data > key)
    {
        root->left = deletenode(root->left , key);
    }
    if (root->data < key)
    {
        root->right = deletenode(root->right , key);
    }
    return root;
}

int minValue(treenode* root) {
    if(root == NULL){
        return -1;
    }
    int mini = root->data;
    while(root->left != NULL){
        root = root->left;
    }
    return min(mini , root->data);
}

void PreAndSucc(treenode* root , treenode* &pre , treenode* &succ , int key){
    if(root == NULL){
        return;
    }
    if (root->data == key)
    {
        if (root->left != NULL)
        {
            treenode* tmp = root->left;
            while (tmp->right != NULL)
            {
                tmp = tmp->right;
            }
            pre = tmp;
        }
        if (root->right != NULL)
        {
            treenode* tmp = root->right;
            while (tmp->left != NULL)
            {
                tmp = tmp->left;
            }
            succ = tmp;
        }
    }
    else if (root->data < key)
    {
        pre = root;
        PreAndSucc(root->right, pre , succ , key);
    }
    else
    {
        succ = root;
        PreAndSucc(root->left , pre , succ , key);
    }
}

treenode* LCA(treenode* root , int n1 , int n2){
    if (root == NULL)
    {
        return root;
    }
    if (root->data > n1 && root->data > n2)
    {
        return LCA(root->left , n1 , n2);
    }
    if (root->data < n1 && root->data < n2)
    {
        return LCA(root->right , n1 , n2);
    }
    return root;
}

treenode* helper(int pre[] , char prech[] , int n , int i){
    if (i >= n)
    {
        return NULL;
    }
    treenode* root = new treenode(pre[i]);
    if (prech[i] == 'N')
    {
        root->left = helper(pre , prech , n , i+1);
        root->right = helper(pre , prech , n , i+1);
    }
    return root;
}

treenode* constructfrompreorder(int pre[] , char prech[] , int n){
    int i = 0;
    return helper(pre , prech , n , i);
}

void inorder(treenode* root , vector<int> &in){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left , in);
    in.push_back(root->data);
    inorder(root->right , in);
}

treenode* constructfrominorder(vector<int> in , int i , int j){
    if (i>j)
    {
        return NULL;
    }
    int mid = (i+j)/2;
    treenode* root = new treenode(in[mid]);
    root->left = constructfrominorder(in , i , mid-1);
    root->right = constructfrominorder(in , mid+1 , j);
    return root;
}

treenode* convertBTtoBST(treenode* root){
    vector<int> in;
    inorder(root, in);
    sort(in.begin() , in.end());
    return constructfrominorder(in , 0 , in.size()-1);
}

void inordermap(treenode* root , unordered_map<int,int> &mp){
    if (root == NULL)
    {
        return;
    }
    inordermap(root->left , mp);
    mp[root->data]++;
    inordermap(root->right , mp);
}

int countPairs(treenode* root1 , treenode* root2 , int key){
    unordered_map<int , int> mp1 , mp2;
    inordermap(root1 , mp1);
    inordermap(root2 , mp2);
    int count = 0;
    for(auto it : mp1){
        int a = key - it.first;
        if (mp2[a] > 0)
        {
            count++;
        }
    }
    return count;
}

void inorderpr(treenode* root , treenode* &prev){
    if (root == NULL)
    {
        return;
    }
    inorderpr(root->left , prev);
    prev->left = NULL;
    prev->right = root;
    prev = root;
    inorderpr(root->right , prev);
}

treenode* flatten(treenode* root){
    treenode* dumy = new treenode(-1);
    treenode* prev = dumy;
    inorderpr(root , prev);
    prev->left = NULL;
    prev->right = NULL;
    treenode* ret = dumy->right;
    delete dumy;
    return ret;
}

int main(){

}