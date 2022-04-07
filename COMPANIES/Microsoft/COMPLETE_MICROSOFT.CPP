#include<bits/stdc++.h>
using namespace std;

//-------------max subarr sum-----------------------//

int maxsubarrsum(int arr[] , int n){
    int sum = 0;
    int maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
        }
        maxsum = max(sum , maxsum);
    }
    return maxsum;
}

//--------------find duplicate----------------//

int findDuplicate(int arr[] , int n){
    vector<bool> v(n+1 , false);
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        if (v[a] == true)
        {
            return a;
        }
        v[a] = true;
    }
    return -1;
}

//----------------SPIRAL ORDER MATRIX------------//

void spiralorder(vector<vector<int>> v){
    int i = 0 , j = 0;
    int n = v.size() , m = v[0].size();
    while (i <= n && j <= m)
    {
        for (int k = j; k < m; k++)
        {
            cout<<v[i][k]<<" ";
        }
        i++;
        for (int k = i; k < n; k++)
        {
            cout<<v[k][m]<<" ";
        }
        m--;
        if (j < m)
        {
            for (int k = m-1; k >= j; k--)
            {
                cout<<v[n-1][k]<<" ";
            }
            n--;
        }
        if (i < n)
        {
            for (int k = n-1; k >= i; k--)
            {
                cout<<v[k][j]<<" ";
            }
            j++;
        }
    }
}

//----------------largest number made using string--------------------//

static bool cmp(int a , int b){
    string a1 = to_string(a);
    string b1 = to_string(b);
    return a1+b1 > b1+a1;
}

string largestno(vector<int> v){
    sort(v.begin() , v.end() , cmp);
    string ans = "";
    int c = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans += to_string(v[i]);
        if (v[i] == 0)
        {
            c++;
        }
    }
    if (c == v.size())
    {
        return "0";
    }
    return ans;
}

//----------find missing no--------------//

int firstmissinginteger(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && arr[i] <= n)
        {
            int pos = arr[i]-1;
            if (arr[pos] != arr[i])
            {
                swap(arr[pos] , arr[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i+1)
        {
            return i+1;
        }
    }
    return n+1;
}

vector<int> addone(vector<int> v){
    reverse(v.begin() , v.end());
    int carry = 1;
    for (int i = 0; i < v.size(); i++)
    {
        int sum = v[i] + carry;
        v[i] = sum%10;
        carry = sum/10;
    }
    if (carry != 0)
    {
        v.push_back(carry);
    }
    reverse(v.begin() , v.end());
    int k = 0;
    while (v.front() == 0)
    {
        auto it = v.begin();
        v.erase(it+k);
    }
    return v;
}

//--------------------------next permuatation---------------------------//

vector<int> nextpermu(vector<int> v){
    int n = v.size();
    int k , l;
    for (k = n-2; k >= 0; k--)
    {
        if (v[k] < v[k+1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(v.begin() , v.end());
    }
    else
    {
        for (l = n-1; l >= k; l--)
        {
            if (v[l] > v[k])
            {
                break;
            }
        }
        swap(v[l] , v[k]);
        reverse(v.begin()+k+1 , v.end());
    }
    return v;
}

//---------------------------ANTIDIGONALS---------------------------//

vector<vector<int>> antidiagonals(vector<vector<int>> v){
    vector<vector<int>> ans;
    int n = v.size();
    int m = v[0].size();
    int b = n-1+n-1;
    for (int k = 0; k <= b; k++)
    {
        vector<int> v1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i+j) == k)
                {
                    v1.push_back(v[i][j]);
                }
            }
        }
        ans.push_back(v1);
    }
    return ans;
}

//-----------------hotel booking------------------//

bool hotelbooking(vector<int> v1 , vector<int> v2 , int k){
    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());
    for (int i = k; i < v1.size(); i++)
    {
        if (v1[i] < v2[i-k])
        {
            return false;
        }
    }
    return true;
}

//-------------------GRID unique path------------------------//

int griduniquepath(int n , int m){
    int dp[n][m];
    memset(dp , 1 , sizeof(dp));
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}

//-----------------trailing zeros-------------------//

int trailingzeros(int n){
    int c = 0;
    for (int i = 5; (n/i) > 0; i *= 5)
    {
        c += (n/i);
    }
    return c;
}

//---------------sorted permuatation rank-----------------//
int mod = 1000007;

int fact(int n){
    if (n == 0)
    {
        return 0;
    }
    return n*fact(n-1)%mod;
}

int sortedpermuattionrank(string a){
    string s = a;
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = i+1; j < n; j++)
        {
            if (s[j] < s[i])
            {
                c++;
            }
        }
        ans += c*(fact(n-i-1)) % mod;
    }
    return ans%mod;
}

//------------------------median of 2 arrays----------------------------//

int median_of_arr(int arr1[] , int arr2[] , int n , int m){
    if (n > m)
    {
        return median_of_arr(arr2 , arr1 , m , n);
    }
    int lo = 0 , hi = n-1;
    int l1 , l2 , r1 , r2;
    while (lo <= hi)
    {
        int cut1 = (lo+hi)/2;
        int cut2 = (n+m)/2 - cut1;
        l1 = (cut1 == 0) ? INT_MIN : arr1[cut1-1];
        l2 = (cut2 == 0) ? INT_MIN : arr2[cut2-1];
        r1 = (cut1 == 0) ? INT_MAX : arr1[cut1];
        r2 = (cut2 == 0) ? INT_MAX : arr2[cut2];
        if (l1 > r2)
        {
            hi = cut1-1;
        }
        else if (l2 > r1)
        {
            lo = cut1+1;
        }
        else
        {
            return (n+m)%2 == 0 ? (max(l1 , l2) + min(r1 , r2))/2.0 : min(r1 , r2);
        }
    }
}

//------------search for range----------------------//

int firstele(vector<int> v , int b){
    int lo = 0 , hi = v.size() - 1;
    int ans = -1;
    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if (v[mid] == b)
        {
            ans = mid;
            hi = mid-1;
        }
        else if (v[mid] > b)
        {
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
    return ans;
}

int secondele(vector<int> v , int b){
    int lo = 0 , hi = v.size() - 1;
    int ans = -1;
    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if (v[mid] == b)
        {
            ans = mid;
            lo = mid+1;
        }
        else if (v[mid] > b)
        {
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
    return ans;
}

vector<int> searchrange(vector<int> v , int b){
    vector<int> v;
    int a = firstele(v , b);
    if(a == -1){
        v.push_back(-1);
        v.push_back(-1);
        return v;
    }
    v.push_back(a);
    int b = secondele(v , b);
    v.push_back(b);
    return v;
}

//-----------------------------square root of number-----------------------//

int squareroot(int n){
    long long int i = 0 , j = n;
    long long int mid = i+(j-i)/2;
    long long int ans = -1;
    while(i <= j){
        // int mid = (i+j)/2;
        long long int sq = mid*mid;
        if(sq == n){
            return mid;
        }
        if(sq > n){
            j = mid-1;
        }
        else{
            ans = mid;
            i = mid+1;
        }
        mid = i+(j-i)/2;
    }
    return ans;
}

//-------------------------------rotated search array search------------------//

int rotatedsearcharr(vector<int> v,int b){
    int n=v.size();
    int l=0,r=n-1;
    while(l<=r)
    {
        int m=l+(r-l)/2;
        if(v[m]==b)
        {
            return m;
        }
        else if(v[m] >= v[l])
        {
            if(v[l]<= b && v[m] >= b)
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        else
        {
            if(v[r] >= b && v[m] <= b)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
    }
    return -1;
}

//------------------------------implement array-------------------------//

int implementstring(string a , string b){
    int n = a.length();
    int m = b.length();
    if (b == "")
    {
        return 0;
    }
    if (m > n)
    {
        return -1;
    }
    for (int i = 0; i < n-m+1; i++)
    {
        if (a.substr(i , m) == b)
        {
            return i;
        }
    }
    return -1;
}

//-----------------Integer to roman----------------------//

string integertoroman(int n){
    string str[] = {"M" , "CM" , "D" , "CD" , "C" , "XC" , "L" , "XL" , "X" , "IX" , "V" , "IV" , "I"};
    int val[] = {1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4 , 1};
    
    string s = "";
    for(int i=0; n!=0 ; i++){
        while(n >= val[i]){
            n -= val[i];
            s += str[i];
        }
    }
    return s;
}

//----------------Roman to Integer----------------------//

int romantoint(string A){
    unordered_map<char , int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int n = A.length();
    int sum = mp[A[n-1]];
    for(int i=n-2;i>=0;i--){
        if(mp[A[i]] < mp[A[i+1]]){
            sum -= mp[A[i]];
        }
        else{
            sum += mp[A[i]];
        }
    }
    return sum;
}

//-----------------multiply strings-------------------//

string multiplystrings(string a , string b){
    int n = a.length() , m = b.length();
    string res(n+m , '0');
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            int num = (a[i] - '0')*(b[i] - '0') + res[i+j+1] - '0';
            res[i+j+1] = num%10 +'0';
            res[i+j] += num/10;
        }
    }
    for(int i=0;i<res.length();i++){
        if(res[i] != '0'){
            return res.substr(i);
        }
    }
    return "0";
}

//------------------Divide Integers---------------------//

int divideint(int a , int b){
    if (a == INT_MIN && b == -1)
    {
        return INT_MAX;
    }
    int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;
    int A = abs(a) , B = abs(b);
    int ans = 0;
    while (A >= B)
    {
        A = A-B;
        ans++;
    }
    return ans*sign;
}

//-------------------------------Linked list---------------------//

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

node* takeinput(){
    node* head = NULL;
    node* tail = NULL;

    int data;
    cin>>data;
    while (data != -1)
    {
        node* newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin>>data;
    }
    return head;
}

void print(node* head){
    node* t = head;
    while (t != NULL)
    {
        cout<<t->data<<" ";
        t = t->next;
    }
}

//--------------------remove duplicate 1 -----------------------------//

node* removeduplicate1(node* head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node* curr = head;
    while (curr != NULL)
    {
        if (curr->data == curr->next->data)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

//-----------------------------remove duplicate 2------------------------//

node* removeduplicate2(node* head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node* temp = head;
    while (head->next != NULL && head->next->data == head->data)
    {
        head = head->next;
    }
    if (temp == head)
    {
        head->next = removeduplicate2(head->next);
        return head;
    }
    else
    {
        head = head->next;
        return removeduplicate2(head);
    }
}

//--------------------------add 2 number------------------------//

node* add2number(node* head1, node* head2){
    node* newnode = new node(-1);
    node* temp = newnode;
    int a = 0 , b = 0 , carry = 0;
    while (head1 != NULL || head2 != NULL || carry != 0)
    {
        if (head1 != NULL)
        {
            a = head1->data;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            b = head2->data;
            head2 = head2->next;
        }
        int sum = a+b+carry;
        node* d = new node(sum%10);
        carry = sum/10;
        newnode->next = d;
        newnode = d;
        a = b = 0;
    }
    return newnode->next;
}

//----------------------------reverse k list ---------------------------//

node* reverselist(node* head , int k){
    node* curr = head;
    node* prev = NULL;
    node* temp = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }
    if (temp != NULL)
    {
        head->next = reverselist(temp , k);
    }
    return prev;
}

//-------------------------------IS palindrome ---------------------------------//

node* findmid(node* head){
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* reve(node* head){
    node* curr = head;
    node* temp = NULL;
    node* prev = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

bool palindrome(node* head){
    node* temp = head;
    node* mid = findmid(head);
    node* part2 = mid->next;
    mid->next = NULL;
    part2 = reve(part2);
    while (temp != NULL && part2 != NULL)
    {
        if (temp->data != part2->data)
        {
            return false;
        }
        temp = temp->next;
        part2 = part2->next;
    }
    return false;
}

//-----------------------------Detect loop--------------------------------//

node* detectloop(node* head){
    node* slow = head;
    node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            while(head!=slow){
                head=head->next;
                slow=slow->next;
            }
            return slow;
        }
    }
    return NULL;
}

//-------------------------INTERSECTION OF LINKED LIST------------------------//

node* getintersectionnode(node* headA , node* headB){
    int m, n;
    m = n = 0;
    node *p = headA, *q = headB;
        
    while(p != nullptr)
    {
        p = p->next;
        ++m;
    }
        
    while(q != nullptr)
    {
        q = q->next;
        ++n;
    }
        
    p = headA;
    q = headB;
        
    if(m > n) 
    {
        for(int i = 0; i < m - n; i++) p = p->next;
    }
    else
    {
        for(int i = 0; i < n - m; i++) q = q->next;
    }
        
    while(p != nullptr)
    {
        if(p == q) return p;
        p = p->next;
        q = q->next;
    }
    return nullptr;
}

//-------------------------------------------------------------------
//---------------------------Rain water trapping ----------------------//

int trappingrainwater(int arr[] , int n){
    int left[n] , right[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1] , arr[i]);
    }
    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        right[i] = max(right[i+1] , arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (min(left[i] , right[i]) - arr[i]);
    }
    return ans;
}

//----------------------HASHING--------------------//
//------------------------------------ANAGRAMS----------------------------//
vector<vector<int>> anagrams(const vector<string> &A) {
    unordered_map<string , vector<int>> mp;
    for(int i=0;i<A.size();i++){
        string t = A[i];
        sort(t.begin() , t.end());
        mp[t].push_back(i+1);
    }
    vector<vector<int>> v;
    for(auto it : mp){
        v.push_back(it.second);
    }
    return v;
}

//------------------------------TREES------------------------------//

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

treenode* takeinputtree(){
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

//-------------------------print level wise---------------------------//

void printlevelwise(treenode* root){
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        treenode* currnode = pendingnodes.front();
        pendingnodes.pop();
        string tobeprinted = to_string(currnode->data)+" : ";
        if (currnode->left != NULL)
        {
            tobeprinted += "L : "+to_string(currnode->left->data)+",";
            pendingnodes.push(currnode->left);
        }
        else
        {
            tobeprinted += "L : -1";
        }
        if (currnode->right != NULL)
        {
            tobeprinted += "R : "+to_string(currnode->right->data)+",";
            pendingnodes.push(currnode->right);
        }
        cout<<tobeprinted<<endl;
    }
}

//------------------------------------inorder traversal---------------------------//

void inorder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//-----------------------------recover BST--------------------------------//

void find(treenode* root , vector<int> v , int prev){
    if (root == NULL)
    {
        return;
    }
    find(root->left , v , prev);
    if (prev != -1)
    {
        if (prev > root->data)
        {
            v[0] = min({prev , v[0] , root->data});
            v[1] = max({prev , v[1] , root->data});
        }
    }
    prev = root->data;
    find(root->right , v , prev);
}

vector<int> recover(treenode* root){
    vector<int> v(2 , -1);
    v[0] = INT_MAX;
    v[1] = INT_MIN;
    int prev = -1;
    find(root, v , prev);
    return v;
}

//--------------------------------------LCA--------------------------------------//

treenode* LCA(treenode* root , int n1 , int n2){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    treenode* leftLCA = LCA(root->left , n1 , n2);
    treenode* rightLCA = LCA(root->right , n1 , n2);
    if (leftLCA != NULL && rightLCA != NULL)
    {
        return root;
    }
    if (leftLCA == NULL && rightLCA == NULL)
    {
        return NULL;
    }
    if (leftLCA != NULL)
    {
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

//---------------------build tree using preorder and inorder-----------------------//

treenode* helper(vector<int> ino , vector<int> pre , int instart , int inend , int prestart){
    if (instart > inend)
    {
        return NULL;
    }
    int index = instart;
    while (ino[index] != pre[prestart])
    {
        index++;
    }
    treenode* root = new treenode(ino[index]);
    prestart++;
    root->left = helper(ino , pre , instart , index - 1 , prestart);
    root->right = helper(ino , pre , index+1 , inend , prestart);
    return root;
}

treenode* buildtree(vector<int> ino , vector<int> pre){
    int t = 0;
    return helper(ino , pre , 0 , pre.size()-1 , t);
}

//--------------------preorder traversal---------------------//

void preorder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//----------------------max depth--------------------------//

int height(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return 1+max(height(root->left) , height(root->right));
}

//----------------------build tree using inorder and postorder---------------------//

treenode* tree(vector<int> &ino , int instart , int inend ,  vector<int> &post , int postart , int poend){
    if(instart > inend || postart > poend){
        return NULL;
    }
    treenode* root = new treenode(post[poend]);
    int s1 = instart;
    while(root->data != ino[s1]){
        s1++;
    }
    root->left = tree(ino , instart , s1-1 , post , postart , postart+s1-instart-1);
    root->right = tree(ino , s1+1 , inend , post , postart+s1-instart , poend-1);
    return root;
}

treenode* buildTree(vector<int> &A, vector<int> &B) {
    return tree(A , 0 , A.size()-1 , B , 0 , B.size() - 1);
}

//--------------------sum of root to leaf number------------------------//

void preorder(treenode* root , int currsum , int sum){
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL && root->right != NULL)
    {
        sum += (currsum+root->data);
        return;
    }
    preorder(root->left , (currsum+root->data)*10 , sum);
    preorder(root->right , (currsum+root->data)*10 , sum);
}

int sumnumbers(treenode* root){
    if (root == NULL)
    {
        return;
    }
    int sum = 0;
    preorder(root , 0 , sum);
    return sum;
}
//-------------------------postorder--------------------//

void postorder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//-----------------------populate next right pointer--------------------//

//-----------------------zig zag level order traversal-------------------//

//-----------------------vertical order traversak------------------//

/////////////---------------------------------------DYNAMIC PROGRAMING------------------////////

//-------------LIS-----------------//
//-------------MAX PRODUCT SUBARR-------------//
//------------REGULAR EXPRESSION-----------------------//

int isMatch(const string a, const string b) {
    int n=a.length(),m=b.length();
    vector<vector<bool>> v(n+1,vector<bool>(m+1));
    for(int i=0;i<=n;i++){
        v[i][0]=false;
    }
    v[0][0]=true;
    for(int i=1;i<=m;i++){
        v[0][i]=true;
        for(int j=1;j<=i;j++){
            if(b[j-1]!='*'){
                v[0][i]=false;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1] || b[j-1]=='?'){
                v[i][j]=v[i-1][j-1];
            }
            else if(b[j-1]=='*'){
                v[i][j]=v[i-1][j] || v[i][j-1];
            }
            else{
                v[i][j]=false;
            }
        }
    }
    return v[n][m];
}

//-------------------edit distance----------------------//

//-------------------coin sum infinite------------------//

//-----------------Longest arthematic progression----------//

//-----------------length of longest subsequence-------------//

///////////-----------greedy------------------//

//-------------majority element-------------------//

//-----------------------distribute candy--------------------//

//----------------meeting rooms-----------------------//

int main(){
    
}