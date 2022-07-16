#include<bits/stdc++.h>
using namespace std;

void setMatrixzero(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    bool firstrow = false;
    bool firstcol = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                if(i == 0){
                    firstrow = true;
                }
                if(j == 0){
                    firstcol = true;
                }
                grid[i][0] = 0;
                grid[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (grid[i][0] == 0 || grid[0][j] == 0)
            {
                grid[i][j] = 0;
            }
        }
    }
    if (firstrow)
    {
        for (int i = 0; i < m; i++)
        {
            grid[0][i] = 0;
        }
    }
    if (firstcol)
    {
        for (int i = 0; i < n; i++)
        {
            grid[i][0] = 0;
        }
    }
}

vector<vector<int>> PascalsTriangle(int n){
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].resize(i+1);
        v[i][0] = v[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i-1][j] + v[i-1][j-1];
        }
    }
    return v;
}

vector<int> nextPermutation(vector<int> v){
    int k , l;
    int n = v.size();
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
        for (l = n-1; l > k; l--)
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

int KadanesAlgo(int arr[] , int n){
    int sum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = max(arr[i] , sum+arr[i]);
        maxsum = max(sum , maxsum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxsum;
}

void sort012(vector<int> &v){
    int zeros = 0 , ones = 0 , twos = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            zeros++;
        }
        else if (v[i] == 1)
        {
            ones++;
        }
        else
        {
            twos++;
        }
    }
    int i;
    for (i = 0; i < zeros; i++)
    {
        v[i] = 0;
    }
    for(i; i<(zeros+ones);i++){
        v[i] = 1;
    }
    for (i = 0; i < v.size(); i++)
    {
        v[i] = 2;
    }
}

int Besttimetobuystock(int arr[] , int n){
    int mini = INT_MIN;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini , arr[i]);
        maxi = max(maxi , arr[i] - mini);
    }
    return maxi;
}

void rotateMatrix(vector<vector<int>> grid){
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(grid[i][j] , grid[j][i]);
        }
    }
    for (int i = 0; i < grid.size(); i++)
    {
        reverse(grid[i].begin() , grid[i].end());
    }
}

vector<vector<int>> mergeIntervals(vector<vector<int>> Intervals){
    vector<vector<int>> ans;
    int n = Intervals.size();
    if (n == 0)
    {
        return ans;
    }
    ans.push_back(Intervals[0]);
    for (int i = 1; i < n; i++)
    {
        if (ans[ans.size()-1][1] > Intervals[i][0])
        {
            ans[ans.size()-1][1] = max(ans[ans.size()-1][1] , Intervals[i][1]);
        }
        else
        {
            ans.push_back(Intervals[i]);
        }
    }
    return ans;
}

void merge2arrays(int arr1[] , int arr2[] , int n , int m){
    int i = 0 , j = 0 , k = n-1;
    while (i < k && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[k] , arr2[j]);
            j++;
            k--;
        }
        else
        {
            i++;
        }
    }
    sort(arr1 , arr1+n);
    sort(arr2 , arr2+m);
}

int findDuplicate(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        int ind = abs(arr[i]) - 1;
        arr[i] *= -1;
        if (arr[i] > 0)
        {
            return abs(arr[i]);
        }
    }
    return -1;
}

vector<int> repeating_and_missing_no(int arr[] , int n){
    long long sum = 0;
    long long squaresum = 0;
    long long temp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        sum -= (i+1);
        squaresum += (arr[i]*arr[i]);
        squaresum -= ((i+1)*(i+1));
    }
    squaresum /= sum;
    int a = (squaresum+sum)/2;
    int b = squaresum - a;
    return {a,b};
}

int merge(int arr[],int temp[],int left,int mid,int right)
{
    int inv_count=0;
    int i = left;
    int j = mid;
    int k = left;
    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

int merge_Sort(int arr[],int temp[],int left,int right)
{
    int mid,inv_count = 0;
    if(right > left)
    {
        mid = (left + right)/2;

        inv_count += merge_Sort(arr,temp,left,mid);
        inv_count += merge_Sort(arr,temp,mid+1,right);

        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

int countInversion(int arr[] , int n){
    int count = 0;
    int temp[n];
    merge_Sort(arr ,temp , 0 , n-1);
    return count;
}

bool searchinmatrix(vector<vector<int>> v , int key){
    int n = v.size() , m = v[0].size();
    int lo = 0 , hi = n*m-1;
    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if (v[mid/v[0].size()][mid%v[0].size()] == key)
        {
            return true;
        }
        if (v[mid/v[0].size()][mid%v[0].size()] < key)
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
    return false;
}

double power(double x , int n){
    double res = 1;
    while (n)
    {
        if (n%2)
        {
            res = n > 0 ? res*x : res/x;
        }
        x = x*x;
        n /= 2;
    }
    return res;
}

int majorityele(int arr[] , int n){
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for(auto it : mp){
        if (it.second > n/2)
        {
            return it.first;
        }
    }
    return -1;
}

vector<int> majorityelen3(int arr[] , int n){
    unordered_map<int,int> mp;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for(auto it : mp){
        if (it.second > n/3)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}

int uniquePath(int n , int m){
    vector<vector<int>> dp(n , vector<int>(m , 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}

void checkcount(int arr[] , int s , int mid , int e , int &count){
    int l = s , r = mid+1;
    while (l <= mid && r <= e)
    {
        if (arr[l] > 2*arr[r])
        {
            count += (mid-l+1);
        }
        else
        {
            l++;
        }
    }
    sort(arr+s , arr+e+1);
}

void mergesort(int arr[] , int s, int e , int &count){
    if (s == e)
    {
        return;
    }
    int mid = (s+e)/2;
    mergesort(arr , s , mid , count);
    mergesort(arr , mid+1 , e , count);
    checkcount(arr , s , mid , e , count);
}

int reversePairs(int arr[] , int n){
    if (n <= 0)
    {
        return 0;
    }
    int count = 0;
    mergesort(arr , 0 , n-1 , count);
    return count;
}

vector<int> Twosum(int arr[] , int n , int target){
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(target - arr[i]) != mp.end())
        {
            return {mp[target - arr[i]] , i};
        }
    }
    return {};
}

vector<vector<int>> foursum(vector<int> v , int target){
    sort(v.begin() , v.end());
    vector<vector<int>> ans;

    sort(v.begin() , v.end());
    int n = v.size();
    unordered_map<int,vector<pair<int,int>>> mp;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            mp[v[i]+v[j]].push_back(make_pair(i,j));
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(i > 0 && v[i] == v[i-1]){
            continue;
        }
        for (int j = i+1; j < n; j++)
        {
            if (j > i+1 && v[j] == v[j-1])
            {
                continue;
            }
            int res = target - v[i] - v[j];
            if(mp.count(res)){
                for(auto it = mp[res].begin(); it != mp[res].end(); it++){
                    int k = (*it).first, l = (*it).second;
                    if(k > j){ 
                        if(!ans.empty() && v[i]==ans.back()[0] && v[j]==ans.back()[1] && v[k]==ans.back()[2] && v[l] == ans.back()[3]){
                            continue; 
                        }
                        vector<int> vi={v[i], v[j], v[k], v[l]};
                        ans.push_back(vi);
                    }
                }
            }
        }    
    }
    return ans;
}

int longestconsequtivesequence(int arr[] , int n){
    vector<int> v(1000000007 , -1);
    for (int i = 0; i < n; i++)
    {
        v[arr[i]]++;
    }
    int c = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != -1)
        {
            c++;
            mx = max(mx , c);
        }
        else
        {
            c = 0;
        }
    }
    return mx;
}

int maxlengthfind(int arr[] , int n){
    int maxlength = 0;
    int sum = 0;
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] == 0 && maxlength == 0)
        {
            maxlength = 1;
        }
        if (sum == 0)
        {
            maxlength = i+1;
        }
        if (mp.find(sum) != mp.end())
        {
            maxlength = max(maxlength , i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return maxlength;
}

int subarrwithgivenxor(int arr[] ,int n , int B){
    int ans = 0;
    int xorr = 0;
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        xorr ^= arr[i];
        int tmp = xorr^B;
        ans += mp[tmp];
        if (xorr == B)
        {
            ans++;
        }
        mp[xorr]++;
    }
    return ans;
}

int longestsubstringwithoutrepeatcharacter(string s){
    vector<int> v(256 , -1);
    int left = 0 , right = 0;
    int n = s.length();
    int len = 0;
    while (right < n)
    {
        if (v[s[right]] != -1)
        {
            left = max(left , v[s[right]+1]);
        }
        v[s[right]] = right;
        len = max(len , right-left+1);
        right++;
    }
    return len;
}

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

node* reverse(node* head){
    node* prev = NULL;
    node* curr = head;
    node* temp = NULL;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

node* midele(node* head){
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge2ll(node* head1 , node* head2){
    node* newnode = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->data < head2->data)
    {
        newnode = head1;
        newnode->next = merge2ll(head1->next , head2);
    }
    if (head1->data > head2->data)
    {
        newnode = head2;
        newnode->next = merge2ll(head1 , head2->next);
    }
    return newnode;
}

node* removenthfromend(node* head , int k){
    node* pp = head;
    node* tt = head;
    for (int i = 0; i < k; i++)
    {
        tt = tt->next;
    }
    while (tt->next != NULL)
    {
        tt = tt->next;
        pp = pp->next;
    }
    pp->next = pp->next->next;
    return head;
}

node* add2numbers(node* head1 , node* head2){
    node* l1 = head1 , *l2 = head2 , *l3 = new node(-1);
    node* pre = l3;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int n1 = 0 , n2 = 0;
        if (l1 != NULL)
        {
            n1 = l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            n2 = l2->data;
            l2 = l2->next;
        }
        int sum = n1+n2+carry;
        l3->next = new node(sum%10);
        carry = sum/10;
        l3 = l3->next;
    }
    return pre->next;
}

node* deletenode(node* n){
    n->data = n->next->data;
    n->next = n->next->next;
}

node* getintersection(node* headA , node* headB){
    int m = 0 ,n = 0;
    node* l1 = headA , *l2 = headB;
    while (l1 != NULL)
    {
        m++;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        n++;
        l2 = l2->next;
    }
    l1 = headA;
    l2 = headB;
    if (m > n)
    {
        for (int i = 0; i < m-n; i++)
        {
            l1 = l1->next;
        }
    }
    else
    {
        for (int i = 0; i < n-m; i++)
        {
            l2 = l2->next;
        }
    }
    while (l2 != NULL)
    {
        if (l1 == l2)
        {
            return l1;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return NULL;
}

bool detectLoop(node* head){
    if (head == NULL)
    {
        return false;
    }
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

node* reversellatsizek(node* head , int k){
    node* prev = NULL;
    node* curr = head;
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
        head->next = reversellatsizek(temp , k);
    }
    return prev;
}

bool isPalindrome(node* head){
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* temp = slow->next;
    slow->next = NULL;
    temp = reverse(temp);
    while (head != NULL)
    {
        if (head->data != temp->data)
        {
            return false;
        }
        head = head->next;
        temp = temp->next;
    }
    return true;
}

node* startofloop(node* head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

//------flatten a linked list-----------//
//---------------------------------------

node* rotatelist(node* head , int k){
    int count = 1;
    node* p = head;
    while (p->next)
    {
        p = p->next;
        count++;
    }
    p->next = head;
    p = p->next;
    int t = count - (k%count);
    node* q = NULL;
    while (t > 0)
    {
        if (t == 1)
        {
            q = p;
        }
        t--;
        p = p->next;
    }
    q->next = NULL;
    return p;
}

//--------clone a linked list with random pointer-------------------//
//--------------------------------------------

vector<vector<int>> threesum(vector<int> v){
    int n = v.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && v[i] == v[i-1])
        {
            continue;
        }
        int l = i+1 , r = n-1;
        while (l <= r)
        {
            int sum = v[i]+v[l]+v[r];
            if (sum == 0)
            {
                ans.push_back({i , l , r});
                while (l+1 < r && v[l] == v[l+1])
                {
                    l++;
                }
                while (l < r-1 && v[r] == v[r-1])
                {
                    r--;
                }
                l++;
                r--;
            }
            else if (sum < 0)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return ans;
}

int trappingRainWater(int arr[] , int n){
    int low = 0 , hi = n-1;
    int ml = 0 , mr = 0;
    int ans = 0;
    while (low <= hi)
    {
        if (arr[low] < arr[hi])
        {
            if (arr[low] > ml)
            {
                ml = arr[low];
            }
            else
            {
                ans += (ml - arr[low]);
            }
            low++;
        }
        else
        {
            if (arr[hi] > mr)
            {
                mr = arr[hi];
            }
            else
            {
                ans += (mr - arr[hi]);
            }
            hi--;
        }
    }
    return ans;
}

int removeduplicates(vector<int> v){
    int i = 0 , j = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0 || v[i] != v[j-1])
        {
            v[j] = v[i];
            j++;
        }
    }
    return j;
}

int maxconsequtiveone(vector<int> v){
    int maxcount = 0;
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            maxcount = max(maxcount , count);
            count = 0;
        }
        else
        {
            count++;
        }
    }
    return max(maxcount , count);
}

static bool cmp(pair<int,int> &a , pair<int,int> &b){
    return a.second < b.second;
}
    
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({start[i] , end[i]});
    }
    sort(v.begin() , v.end() , cmp);
    int a = v[0].second;
    int c = 1;
    for(int i=1;i<n;i++){
        if(v[i].first > a){
            c++;
            a = v[i].second;
        }
    }
    return c;
}

int minPlatforms(int arr[] , int dep[] , int n){
    int i = 1 , j = 0;
    sort(arr , arr+n);
    sort(dep , dep+n);
    int maxi = 1;
    int platforms =1;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            platforms++;
            i++;
        }
        else
        {
            platforms--;
            j++;
        }
        maxi = max(maxi , platforms);
    }
    return maxi;
}

static bool cmp1(vector<int> v1 , vector<int> v2){
    return v1[2] > v2[2];
}

vector<int> JobScheduling(vector<vector<int>> arr , int n){
    sort(arr.begin() , arr.end() , cmp1);
    int a = 0 , pro = 0;
    vector<int> v(101 , -1);
    for (int i = 0; i < n; i++)
    {
        int j = arr[i][1] - 1;
        while (j > 0 && v[j] != -1)
        {
            j--;
        }
        if (j >= 0 && v[j] == -1)
        {
            a++;
            pro += arr[i][2];
            v[j] = 1;
        }
    }
    return {a , pro};
}

static bool cmp2(pair<int,int> &p1 , pair<int,int> &p2){
    double a = (double)p1.second/(double)p1.first;
    double b = (double)p2.second/(double)p2.first;

    return a > b;
}

double FractionalKnapsack(int wt[] , int val[] , int W , int n){
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({wt[i] , val[i]});
    }
    sort(v.begin() , v.end() , cmp2);
    double sum = 0.0;
    double wt1 = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (wt1 >= W)
        {
            break;
        }
        if (wt1 + v[i].first < W)
        {
            sum += v[i].second;
            wt1 += v[i].first;
        }
        else if (wt1 < W)
        {
            double a = (double)v[i].second/(double)v[i].first;
            sum += (W-wt1)*a;
            wt1 = W;
        }
    }
    return sum;
}

void helpersub(vector<int> arr , int n , int st , int sum , vector<int> &ans){
    if (st == n)
    {
        ans.push_back(sum);
        return;
    }
    helpersub(arr , n , st+1 , sum , ans);
    helpersub(arr , n , st+1 , sum+arr[st] , ans);
}

vector<int> Subsetsum(vector<int> arr , int n){
    vector<int> ans;
    helpersub(arr , n , 0 , 0 , ans);
    sort(ans.begin() , ans.end());
    return ans;
}

void helpersub2(vector<int> arr , vector<int> v , vector<vector<int>> &ans , int st){
    ans.push_back(v);
    for (int i = st; i < arr.size(); i++)
    {
        if (i != st && arr[i] == arr[i-1])
        {
            continue;
        }
        v.push_back(arr[i]);
        helpersub2(arr , v , ans, st+1);
        v.pop_back();
    }
}

vector<vector<int>> subsetsII(vector<int> arr , int n){
    vector<vector<int>> ans;
    vector<int> v;
    sort(arr.begin() , arr.end());
    helpersub2(arr , v , ans , 0);
    return ans;
}

void helpercomb(vector<int> arr , vector<int> v , vector<vector<int>> &ans , int st , int target){
    if (st == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(v);
        }
        return;
    }
    if (arr[st] <= target)
    {
        v.push_back(arr[st]);
        helpercomb(arr , v , ans , st , target-arr[st]);
        v.pop_back();
    }
    helpercomb(arr ,  v , ans , st+1 , target);
}

vector<vector<int>> combinationsum(vector<int> arr , int target){
    vector<vector<int>> ans;
    vector<int> v;
    helpercomb(arr , v , ans , 0 , target);
    return ans;
}

void helpercombII(vector<int> arr , vector<int> ds , vector<vector<int>> ans , int st , int target){
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = st; i < arr.size(); i++)
    {
        if (i > st && arr[i] == arr[i-1])
        {
            continue;
        }
        if (arr[i] > target)
        {
            break;
        }
        ds.push_back(arr[i]);
        helpercombII(arr , ds , ans , st , target-arr[i]);
        ds.pop_back();
    }
}

vector<vector<int>> combinationsumII(vector<int> arr , int target){
    sort(arr.begin() , arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    helpercombII(arr , ds ,ans , 0 , target);
    return ans;
}

//-----------------------------------------------------------------------------
//----------------------------------DAY - 9 , 10
//-------------------------------------------------------------------------------

double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}


int getnthroot(int n , int m){
    double low = 1 , high = m;
    double eps = 1e-6;
    while ((high - low) > eps)
    {
        double mid = (low + high)/2.0;
        if (multiply(mid , n) < m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }    
}

int countelementslessthanmid(vector<int> v, int x){
    int low=0;
    int high=v.size()-1;
    int mid;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(v[mid]<=x) 
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}

int findMedian(vector<vector<int>> v){
    int n = v.size() , m = v[0].size();
    int low = 1;
    int high = pow(10 , 9);
    int mid;
    while (low <= high)
    {
        mid=low+(high-low)/2;
        int count=0;
        for(int i=0;i<n;i++)
            count+=countelementslessthanmid(v[i],mid);
        if(count<=(n*m/2))
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}

int singleelement(int arr[] , int n){
    int xor1 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 ^= arr[i];
    }
    return xor1;
}

int search(vector<int> arr , int n , int key){
    int n = arr.size();
    int low = 0 , high = n-1;
    while (low < high)
    {
        int mid = (low+high)/2;
        if (arr[mid] > arr[high])
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }
    int rot = low;
    low = 0;
    high = n-1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        int realmid = (mid + rot)%n;
        if (arr[realmid] == key)
        {
            return realmid;
        }
        if (arr[realmid] < key)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}

double helpermedian(vector<int> nums1 , vector<int> nums2){
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2)
    {
        return helpermedian(nums2 , nums1);
    }
    int lo = 0 , hi = n1;
    while (lo <= hi)
    {
        int cut1 = (lo+hi)/2;
        int cut2 = (n1+n2+1)/2 - cut1;
        int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((n1+n2)%2 == 0)
            {
                return (double)(max(l1 , l2) + min(r1 , r2))/2;
            }
            else
            {
                return (double)(max(l1 , l2));
            }
        }
        else if (l1 > r2)
        {
            hi = cut1-1;
        }
        else
        {
            lo = cut1+1;
        }
    }
    return -1.0;
}

double medianofarray(vector<int> nums1 , vector<int> nums2){
    double ans;
    ans = helpermedian(nums1 , nums2);
    return ans;
}

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int , vector<int> , greater<int>> pq;
    for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
        if(pq.size() > k){
            pq.pop();
        }
    }
    return pq.top();
}

vector<int> maximumsumcombination(vector<int> v1 , vector<int> v2 , int k){
    sort(v1.begin() , v1.end() , greater<int>());
    sort(v2.begin() , v2.end() , greater<int>());
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(v1[i]+v2[i]);
    }
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v2.size(); j++)
        {
            if (i != j)
            {
                if (v1[i] + v2[j] >= pq.top())
                {
                    pq.pop();
                    pq.push(v1[i]+v2[j]);
                }
                else
                {
                    break;
                }
            }
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.begin() , ans.end());
    return ans;
}

class MedianFinder {
    priority_queue<int> maxheap;
    priority_queue<int , vector<int> , greater<int>> minheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || maxheap.top() > num){
            maxheap.push(num);
        }
        else{
            minheap.push(num);
        }
        if(maxheap.size() > minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size() > maxheap.size()+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(maxheap.size() == minheap.size()){
            return maxheap.empty() ? 0 : (maxheap.top()+minheap.top())/2.0;
        }
        return (maxheap.size() > minheap.size()) ? maxheap.top() : minheap.top();
    }
};

vector<int> nextsmallerele(vector<int> &A){
    int n = A.size();
    vector<int> v(n);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (st.top() >= A[i])
        {
            st.pop();
        }
        v[i] = st.top();
        st.push(A[i]);
    }
    return v;
}

class LRUCache {
public:
    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val; 
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int, node*>m;
    
    LRUCache(int capacity) {
        cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res; 
        }
    
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_) != m.end()) {
            node* existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if(m.size() == cap) {
          m.erase(tail->prev->key);
          deletenode(tail->prev);
        }
        
        addnode(new node(key_, value));
        m[key_] = head->next; 
    }
};

int largestrectangle(vector<int> v){
    stack<int> st;
    int ans = 0;
    v.push_back(0);
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[st.top()] > v[i])
        {
            int top = v[st.top()];
            st.pop();
            int r = st.empty() ? -1 : st.top();
            ans = max(ans , top*(i-r-1));
        }
        st.push(i);
    }
    return ans;
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int tot = 0 , cnt = 0 , days = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0){
                    tot++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int dx[] = {0 , 0 , -1 , 1};
        int dy[] = {1 , -1 , 0 , 0};
        while (!q.empty())
    {
        int k = q.size();
        cnt += k;
        while (k--)
        {
            int x = q.front().first , y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i] , ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                {
                    continue;
                }
                grid[nx][ny] = 2;
                q.push({nx , ny});
            }
        }
        if (!q.empty())
        {
            days++;
        }
    }
    return tot == cnt ? days : -1;
    }
};

string longestPalindromesequence(string s){
    int n = s.length();
    int dp[n][n];
    memset(dp , 0 , sizeof(dp));
    int mxlen = 0 , st = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        mxlen = 1;
    }
    for (int i = 0; i < n-1; i++)
    {
        if (s[i] == s[i+1])
        {
            dp[i][i+1] = 1;
            mxlen = 2;
            st = i;
        }
    }
    for (int k = 3; k < n; k++)
    {
        for (int i = 0; i < n-k+1; i++)
        {
            int j = i+k-1;
            if (s[i] == s[j] && dp[i+1][j-1] == 1)
            {
                dp[i][j] = 1;
                if (k > mxlen)
                {
                    mxlen = k;
                    st = i;
                }
            }
        }
    }
    return s.substr(st , mxlen);
}

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

void inorder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
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
    queue<treenode*> pendingvertex;
    pendingvertex.push(root);
    while (!pendingvertex.empty())
    {
        int n = pendingvertex.size();
        for (int i = 0; i < n; i++)
        {
            treenode* curr = pendingvertex.front();
            pendingvertex.pop();
            if (i == 0)
            {
                cout<<curr->data<<" ";
            }
            if (curr->left != NULL)
            {
                pendingvertex.push(curr->left);
            }
            if (curr->right != NULL)
            {
                pendingvertex.push(curr->right);
            }
        }
    }
}

void topview(treenode* root){
    unordered_map<int,int> mp;
    queue<pair<treenode* , int>> pendingvertex;
    pendingvertex.push({root , 0});
    while (!pendingvertex.empty())
    {
        treenode* curr = pendingvertex.front().first;
        int h = pendingvertex.front().second;
        if (mp[h] == 0)
        {
            mp[h] = curr->data;
        }
        if (curr->left != NULL)
        {
            pendingvertex.push({curr->left , h-1});
        }
        if (curr->right != NULL)
        {
            pendingvertex.push({curr->right , h+1});
        }
    }
    for(auto it : mp){
        cout<<it.second<<" ";
    }
}

void traverse(treenode* root  , int x , int y , map<int,map<int,multiset<int>>> mp){
    if (root)
    {
        mp[x][y].insert(root->data);
        traverse(root , x-1 , y+1 , mp);
        traverse(root , x+1 , y+1 , mp);
    }
}

vector<vector<int>> verticalorder(treenode* root){
    map<int , map<int , multiset<int>>> mp;
    traverse(root , 0 , 0 , mp);
    vector<vector<int>> ans;
    for(auto it : mp){
        vector<int> col;
        for(auto x : it.second){
            col.insert(col.end() , x.second.begin() , x.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main(){

}