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

void printlevelwise(treenode* root){
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        treenode* currnode = pendingnodes.front();
        pendingnodes.pop();
        string tobeprinted = to_string(currnode->data) + " : ";
        if (currnode->left != NULL)
        {
            tobeprinted += "L : "+ to_string(currnode->left->data)+" , ";
            pendingnodes.push(currnode->left);
        }
        else
        {
            tobeprinted += "L : -1";
        }
        if (currnode->right != NULL)
        {
            tobeprinted += "R : "+to_string(currnode->right->data)+" , ";
            pendingnodes.push(currnode->right);
        }
        else
        {
            tobeprinted += "R : -1";
        }
        cout<<tobeprinted<<endl;
    }
}

bool findNode(treenode* head , int a){
    if (head == NULL)
    {
        return false;
    }
    if (head->data == a)
    {
        return true;
    }
    return findNode(head->left , a) || findNode(head->right , a);
}

treenode* getlargest(treenode* root){
    if (root == NULL)
    {
        return root;
    }
    treenode* maxnode = root;
    if (root->left != NULL)
    {
        treenode* currnode = getlargest(root->left);
        if (currnode->data > maxnode->data)
        {
            maxnode = currnode;
        }
    }
    if (root->right != NULL)
    {
        treenode* currnode = getlargest(root->right);
        if (currnode->data > maxnode->data)
        {
            maxnode = currnode;
        }
    }
    return maxnode;
}

void mirror(treenode* root){
    if (root == NULL)
    {
        return;
    }
    treenode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

int height(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return 1+max(height(root->left) , height(root->right));
}

int diameter(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    
    int leftdiameter = diameter(root->left);
    int rightdiameter = diameter(root->right);

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return max(max(leftdiameter , rightdiameter) , leftheight+rightheight+1);
}

int noofnodesatk(treenode* root , int k){
    if (root == NULL)
    {
        return 0;
    }
    if (k == 0)
    {
        return 1;
    }
    return noofnodesatk(root->left , k-1) + noofnodesatk(root->right , k-1);
}

void inorder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void inorderitr(treenode* root){
    stack<treenode*> st;
    treenode* curr = root;

    while (!st.empty() || curr != NULL)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }
}

void preorder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->left<<" ";
    preorder(root->left);
    preorder(root->right);
}

void preorderitr(treenode* root){
    stack<treenode*> st;
    treenode* curr = root;
    while (!st.empty() && root != NULL)
    {
        while (curr != NULL)
        {
            cout<<curr->data<<" ";
            if (curr->right != NULL)
            {
                st.push(curr->right);
            }
            curr = curr->left;
        }
        if (!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}

void postorder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void leftview(treenode* root){
    if (root == NULL)
    {
        return;
    }
    queue<treenode*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            treenode* curr = q.front();
            q.pop();
            if (i == 0)
            {
                cout<<curr->data<<" ";
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

void rightview(treenode* root){
    if (root == NULL)
    {
        return;
    }
    queue<treenode*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            treenode* curr = q.front();
            q.pop();
            if (i == n-1)
            {
                cout<<curr->data<<" ";
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

void topview(treenode* root){
    map<int,int> mp;
    queue<pair<treenode* , int>> q;
    if (root == NULL)
    {
        return;
    }
    q.push({root , 0});
    while (!q.empty())
    {
        treenode* curr = q.front().first;
        int h = q.front().second;
        if (mp[h] == 0)
        {
            mp[h] = curr->data;
        }
        if (curr->left != NULL)
        {
            q.push({curr->left , h-1});
        }
        if (curr->right != NULL)
        {
            q.push({curr->right , h+1});
        }
    }
    for(auto x : mp){
        cout<<x.second<<" ";
    }
}

void bottomview(treenode* root){
    map<int,int> mp;
    queue<pair<treenode* , int>> q;
    if (root == NULL)
    {
        return;
    }
    q.push({root , 0});
    while (!q.empty())
    {
        treenode* curr = q.front().first;
        int h = q.front().second;
        mp[h] = curr->data;
        if (curr->left != NULL)
        {
            q.push({curr->left , h-1});
        }
        if (curr->right != NULL)
        {
            q.push({curr->right , h+1});
        }
    }
    for(auto x : mp){
        cout<<x.second<<" ";
    }
}

bool isbalanced(treenode* root){
    if (root == NULL)
    {
        return true;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return abs(rightheight-leftheight) <= 1 && isbalanced(root->left) && isbalanced(root->right);
}

int sum(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return root->data + sum(root->left) + sum(root->right);
}

bool issumtree(treenode* root){
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return true;
    }
    int ls = sum(root->left);
    int rs = sum(root->right);
    if ((root->data == ls+rs) && issumtree(root->left) && issumtree(root->right))
    {
        return true;
    }
    return false;
}

treenode* helper(int in[] , int pre[] , int instart , int inend , int preind){
    if (instart > inend)
    {
        return NULL;
    }
    int ind = instart;
    while (in[ind] != in[preind])
    {
        ind++;
    }
    treenode* root = new treenode(in[ind]);
    preind++;
    root->left = helper(in , pre , instart , ind-1 , preind);
    root->right = helper(in , pre , ind+1 , inend , preind);
    return root;
}

treenode* buildtree(int in[] , int pre[] , int n){
    int  t = 0;
    return helper(in , pre , 0 , n-1 , t);
}

treenode* LCA(treenode* root , int n1 , int n2){
    if (root == NULL)
    {
        return root;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    treenode* leftt = LCA(root->left , n1 , n2);
    treenode* rightt = LCA(root->right , n1 , n2);
    if (leftt != NULL && rightt != NULL)
    {
        return root;
    }
    if (leftt == NULL && rightt == NULL)
    {
        return NULL;
    }
    if (leftt != NULL)
    {
        return LCA(root->left , n1 , n2);
    }
    return LCA(root->right , n1 , n2);
}

vector<int> diagonaltraversal(treenode* root){
    if (root == NULL)
    {
        return;
    }
    queue<treenode*> pendingnodes;
    vector<int> ans;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        treenode* curr = pendingnodes.front();
        pendingnodes.pop();
        while (curr != NULL)
        {
            if (curr->left != NULL)
            {
                pendingnodes.push(curr->left);
            }
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }
    return ans;
}

void traversal(treenode* root , int x , int y , map<int,map<int,multiset<int>>> &mp){
    if (root)
    {
        mp[x][y].insert(root->data);
        traversal(root->left , x-1 , y+1 , mp);
        traversal(root->right , x+1 , y+1 , mp);
    }
}

vector<vector<int>> VerticalOrderTraversal(treenode* root){
    map<int , map<int , multiset<int>>> mp;
    vector<vector<int>> ans;
    traversal(root , 0 , 0 , mp);
    for(auto it : mp){
        vector<int> col;
        for(auto p : it.second){
            col.insert(col.end() , p.second.begin() , p.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

//---------------BINARY TREE TO DOUBLY LINKED LIST

string solve(treenode* root , unordered_map<string , int> &mp){
    if (root == NULL)
    {
        return "$";
    }
    string s = "";
    if (root->left == NULL && root->right == NULL)
    {
        s = to_string(root->data);
        return s;
    }
    s += to_string(root->data);
    s += solve(root->left , mp);
    s += solve(root->right , mp);
    mp[s]++;
    return s;
}

bool dupsubtree(treenode* root){
    unordered_map<string , int> mp;
    solve(root , mp);
    for(auto it : mp){
        if (it.second > 1)
        {
            return true;
        }
    }
    return false;
}

int diss(treenode* root , int a , int dis){
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == a)
    {
        return dis;
    }
    int left = diss(root->left , a , dis+1);
    if (left != -1)
    {
        return left;
    }
    return diss(root->right , a , dis+1);
}

int disbtw2nodes(treenode* root , int a , int b){
    treenode* tt = LCA(root , a , b);
    return diss(tt , a , 0) + diss(tt , b , 0);
}

treenode* kthancesstor(treenode* root , int node , int k){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == node || kthancesstor(root->left , node , k) || kthancesstor(root->right , node , k))
    {
        if (k > 0)
        {
            k--;
        }
        else if (k == 0)
        {
            cout<<root->data<<endl;
            return NULL;
        }
        return root;
    }
}

int solve11(treenode* root , int &sum){
    if (root == NULL)
    {
        return 0;
    }
    int leftsum = root->data + solve11(root , sum);
    int rightsum = root->data + solve11(root , sum);
    sum = max({sum , leftsum , rightsum , leftsum+rightsum-root->data , root->data});
    return max({leftsum , rightsum , root->data});
}

int maxPathSum(treenode* root){
    int sum = INT_MIN;
    solve11(root , sum);
    return sum;
}

void DFS(treenode* A ,vector<int> val,vector<vector<int>> &final){
    if(!A){
        return ;
    }
    val.push_back(A->data);
    if(!A->left && !A->right){
        final.push_back(val);
    }
    DFS(A->left,val,final);
    DFS(A->right,val,final);
}

vector<vector<int> > pathSum(treenode* A, int B) {
    vector<vector<int>> final;
    if(!A){
        return final;
    }
    vector<int> val;
    DFS(A,val,final);
    vector<vector<int>> ans;
    for(auto x:final){
        int sum = 0;
        for(auto y:x){
            sum+=y;
        }
        if(sum==B){
            ans.push_back(x);
        }
    }
    return ans;
}

treenode* merge2bt(treenode* root1 , treenode* root2){
    if(root1 && root2){
        treenode* root = new treenode(root1->data + root2->data);
        root->left = merge2bt(root1->left , root2->left);
        root->right = merge2bt(root1->right , root2->right);
        return root;
    }
    else
    {
        return root1 ? root1 : root2;
    }
}

vector<int> cousinsBT(treenode* root , int b){
    vector<int> ans;
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);

    treenode* tt = NULL;
    int flag = 0;

    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 1; i <= n; i++)
        {
            treenode* curr = pendingnodes.front();
            pendingnodes.pop();
            if (curr->left != NULL)
            {
                pendingnodes.push(curr->left);
                if (curr->left->data == b)
                {
                    tt = curr;
                    flag = 1;
                }
            }
            if (curr->right != NULL)
            {
                pendingnodes.push(curr->right);
                if (curr->right->data == b)
                {
                    tt = curr;
                    flag = 1;
                }
            }
        }
        if (flag)
        {
            break;
        }
    }
    if (flag == 0)
    {
        return ans;
    }
    while (!pendingnodes.empty())
    {
        treenode* curr = pendingnodes.front();
        if ((tt->right != NULL && tt->right->data == curr->data) || (tt->left != NULL && tt->left->data == curr->data))
        {
            pendingnodes.pop();
            curr = pendingnodes.front();
            continue;
        }
        ans.push_back(curr->data);
        pendingnodes.pop();
    }
    return ans;
}

int main(){

}