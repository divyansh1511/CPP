#include<bits/stdc++.h>
using namespace std;

void reversearr(int arr[] , int n){
    int i = 0 , j = n-1;
    while (i < j)
    {
        swap(arr[i] , arr[j]);
        i++;
        j--;
    }
}

void min_max(int arr[] , int n){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini , arr[i]);
        maxi = max(maxi , arr[i]);
    }
    cout<<mini<<" "<<maxi<<endl;
}

int kthmaxele(int arr[] , int n , int k){
    priority_queue<int , vector<int> , greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

void sort012(int arr[] , int n){
    int zeros = 0 , ones = 0 , twos = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zeros++;
        }
        else if (arr[i] == 1)
        {
            ones++;
        }
        else
        {
            twos++;
        }
    }
    int i = 0;
    for (i; i < zeros; i++)
    {
        arr[i] = 0;
    }
    for (i; i < (zeros+ones); i++)
    {
        arr[i] = 1;
    }
    for (i; i < n; i++)
    {
        arr[i] = 2;
    }
}
///---1st method
void move_negative_to_side(int arr[] , int n){
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
            {
                swap(arr[i] , arr[j]);
            }
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
///--2nd method

void move_negative(int arr[] , int n){
    int l = 0, r = n-1;
    while (l <= r)
    {
        if (arr[l] < 0 && arr[r] < 0)
        {
            l++;
        }
        else if (arr[l] > 0 && arr[r] < 0)
        {
            swap(arr[l] , arr[r]);
            l++;
            r--;
        }
        else if (arr[l] > 0 && arr[r] > 0)
        {
            r--;
        }
        else
        {
            l++;
            r--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }   
}

vector<int> unionofarr(int arr1[] , int arr2[] , int n , int m){
    set<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s.insert(arr2[i]);
    }
    for(auto it : s){
        ans.push_back(it);
    }
    return ans;
}

vector<int> intersectionofarr(int arr1[] , int arr2[] , int n , int m){
    vector<int> v;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr1[i]);
    }
    for(int i=0;i<m;i++){
        if(s.count(arr2[i])){
            v.push_back(arr2[i]);
            s.erase(arr2[i]);
        }
    }
    return v;
}

void rotatebyone(int arr[] , int n){
    int t = arr[0];
    for (int i = 0; i < n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[n-1] = t;
}

int maxsubarrsum(int arr[] , int n){
    int maxsum = 0;
    int currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        maxsum = max(currsum , maxsum);
        if (currsum < 0)
        {
            currsum = 0;
        }
    }
    return maxsum;
}

int minimize_heights(int arr[] , int n , int k){
    sort(arr , arr+n);
    int diff = arr[n-1] - arr[0];
    for (int i = 1; i < n; i++)
    {
        int maxi = max(arr[i-1]+k , arr[n-1]-k);
        int mini = min(arr[0]+k , arr[i]-k);
        diff = min(diff , maxi - mini);
    }
    return diff;
}

int minjumps(int arr[] , int n){
    if (n <= 1)
    {
        return 0;
    }
    if (arr[0] == 0)
    {
        return -1;
    }
    int maxreach = arr[0];
    int jumps = 1;
    int steps = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (i == n-1)
        {
            return jumps;
        }
        maxreach = max(maxreach , maxreach + arr[i]);
        steps--;
        if (steps == 0)
        {
            jumps++;
            if (i >= maxreach)
            {
                return -1;
            }
            steps = maxreach-i;
        }
    }
    return jumps;
}
///--1st method
int findDuplicate(int arr[] , int n){
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for(auto it : mp){
        if(it.second > 1){
            return it.first;
        }
    }
    return -1;
}
///--2nd method

int findduplicate(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        int ind = abs(arr[i]) - 1;
        arr[ind] *= -1;
        if (arr[ind] > 0)
        {
            return abs(arr[i]);
        }
    }
    return -1;
}

void merge2sortedarr(int arr1[] , int arr2[] , int n , int m){
    int i = 0 , j = 0 , k = n-1;
    while (i <= k && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[k] , arr2[j]);
            k--;
            j++;
        }
        else
        {
            i++;
        }
    }
    sort(arr1 , arr1+n);
    sort(arr2 , arr2+n);
}

vector<vector<int>> mergeIntervals(vector<vector<int>> In){
    vector<vector<int>> ans;
    if (In.size() == 0)
    {
        return ans;
    }
    sort(In.begin() , In.end());
    ans.push_back(In[0]);
    int j = 0;
    for (int i = 1; i < In.size(); i++)
    {
        if (ans[j][1] > In[i][0])
        {
            ans[j][1] = max(ans[j][1] , In[i][1]);
        }
        else
        {
            ans.push_back(In[i]);
            j++;
        }
    }
    return ans;
}

void nextpermutation(vector<int> v , int n){
    int k , l;
    for(k = n-2;k>=0;k--){
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
}

//--count Inversion

void merge(int arr[] , int l , int mid , int r , int &count){
    int i=l;
    int j=mid+1;
    int k=l;
    int B[r+1];
        
    while(i<=mid && j<=r){
        if(arr[i]>arr[j]){
            count+=mid-i+1; //extra line added in merge sort
            B[k++]=arr[j++];        
        }
        else B[k++]=arr[i++];
    }
        
    while(i<=mid){
        B[k++]=arr[i++];
    }
    while(j<=r){
        B[k++]=arr[j++];
    }

    for(int k=l;k<=r;k++){
        arr[k]=B[k];
    }    
}

void mergesort(int arr[] , int i , int j , int &count){
    if (i >= j)
    {
        return;
    }
    int mid = (i+j)/2;
    mergesort(arr , i , mid , count);
    mergesort(arr , mid+1 , j , count);
    merge(arr , i , mid , j , count);
}

int countInversion(int arr[] , int n){
    int count = 0;
    mergesort(arr , 0 , n-1 , count);
    return count;
}

int best_time_to_buy_sell(int arr[] , int n){
    int mini = INT_MAX;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini , arr[i]);
        maxi = max(maxi , arr[i]-mini);
    }
    return maxi;
}

int twosum(int arr[] , int n , int k){
    unordered_map<int,int> mp;
    int c = 0;
    for(int i=0;i<n;i++){
        if(mp.find(k-arr[i]) != mp.end()){
            c += mp[k-arr[i]];
        }
        mp[arr[i]]++;
    }
    return c;
}

vector<int> commmonele(int arr1[] , int arr2[] , int arr3[] , int n1 , int n2 , int n3){
    set<int> s1 , s2 , s3;
    vector<int> v;
    for (int i = 0; i < n1; i++)
    {
        s1.insert(arr1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        s2.insert(arr2[i]);
    }
    for (int i = 0; i < n3; i++)
    {
        if(s1.find(arr3[i]) != s1.end() && s2.find(arr3[i]) != s2.end()){
            if (s3.find(arr3[i]) == s3.end())
            {
                v.push_back(arr3[i]);
            }
            s3.insert(arr3[i]);
        }
    }
    return v;
}

void rearrangethearr(int arr[] , int n){
    int i = -1 , j = n-1;
    while (i < j)
    {
        while (i <= n-1 && arr[i] > 0)
        {
            i++;
        }
        while (j >= 0 && arr[j] < 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i] , arr[j]);
        }
    }
    if (i == 0 || i == n)
    {
        return;
    }
    int k = 0;
    while (k < n && i < n)
    {
        swap(arr[k] , arr[i]);
        i = i+1;
        k = k+2;
    }
}

bool subarrwithsumzero(int arr[] , int n){
    int sum = 0;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0 || s.find(sum) != s.end())
        {
            return true;
        }
        s.insert(sum);
    }
    return false;
}

int maxproduct(int arr[] , int n){
    int minival = arr[0];
    int maxival = arr[0];
    int maxpro = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(minival , maxival);
        }
        maxival = max(maxival , maxival*arr[i]);
        minival = min(minival , minival*arr[i]);
        maxpro = max(maxpro , maxival);
    }
    return maxpro;
}

int longestConsequtive(int arr[] , int n){
    vector<int> v(1000000 , -1);
    for(int i=0;i<n;i++){
        v[arr[i]]++;
    }
    int c = 0;
    int mxc = 0;
    for(int i = 0;i<v.size();i++){
        if(v[i] != -1){
            c++;
        }
        else{
            if(c != 0){
                mxc = max(mxc , c);
            }
            c = 0;
        }
    }
    return mxc;
}

void findele(int arr[] , int n , int k){
    int x = n / k;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]] += 1;

    for (int it = 0; it < mp.size(); it++) {
        if (mp[it] > x)
            cout << (it) << endl;
    }
}

bool threeSum(int arr[] , int n , int sum){
    sort(arr , arr+n);
    for (int i = 0; i < n-2; i++)
    {
        int l = i+1;
        int r = n-1;
        while (l < r)
        {
            if(arr[i]+arr[l]+arr[r] == sum){
                return true;
            }
            else if (arr[i] + arr[l] + arr[r] < sum)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return false;
}

int trappingRainWater(int arr[] , int n){
    int left[n];
    int right[n];
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
        ans += min(left[i] , right[i]) - arr[i];
    }
    return ans;
}

int trappingopti(int arr[] , int n){
    int lo = 0 , hi = n-1;
    int mi = 0 , ma = 0;
    int ans = 0;
    while (lo <= hi)
    {
        if (arr[lo] < arr[hi])
        {
            if (arr[lo] > mi)
            {
                mi = arr[lo];
            }
            else
            {
                ans = ans + (mi - arr[lo]);
            }
            lo++;
        }
        else
        {
            if (arr[hi] > ma)
            {
                ma = arr[hi];
            }
            else
            {
                ans = ans + (ma - arr[hi]);
            }
            hi--;
        }
    }
    return ans;
}

double merdian2arrays(vector<int> arr1 , vector<int> arr2){
    int n = arr1.size() , m = arr2.size();
    if (n > m)
    {
        return merdian2arrays(arr2 , arr1);
    }
    int lo = 0 , hi = n-1;
    while (lo < hi)
    {
        int cut1 = (lo+hi)/2;
        int cut2 = (n+m+1)/2 - cut1;
        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];
            
        if(l1 <= r2 && l2 <= r1){
            if((n+m)%2==0)
                return (double)(max(l1,l2)+min(r1,r2))/2;
            else
                return (double)(max(l1,l2));
        }
        else if(l1 > r2){
            hi = cut1 - 1;
        }
        else{
            lo = cut1 + 1;
        }
    }
    return -1.0;
}

vector<int> max_sliding_window(int arr[] , int n , int k){
    deque<int> dq;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() == i-k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && arr[dq.front()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k-1)
        {
            v.push_back(arr[dq.front()]);
        }
    }
    return v;
}

vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string , vector<string>> mp;
    for (auto s : strs)
    {
        string t = s;
        sort(t.begin() , t.end());
        mp[t].push_back(s);
    }
    vector<vector<string>> v;
    for (auto it : mp)
    {
        v.push_back(it.second);
    }
    return v;
}

void setmatrixzero(vector<vector<int>> v){
    int n = v.size();
    int m = v[0].size();
    bool firstrow = false;
    bool firstcol = false;
    for (int i = 0; i < m; i++)
    {
        if (v[0][i] == 0)
        {
            firstrow = true;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i][0] == 0)
        {
            firstcol = true;
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                v[i][0] = 0;
                v[0][i] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][0] == 0 || v[0][j] == 0)
            {
                v[i][j] = 0;
            }
        }
    }
    if (firstrow)
    {
        for (int i = 0; i < m; i++)
        {
            v[0][i] = 0;
        }
    }
    if (firstcol)
    {
        for (int i = 0; i < n; i++)
        {
            v[i][0] = 0;
        }
    }
}

vector<int> sortwithsquares(vector<int> arr){
    int n = arr.size();
    int left = 0;
    int right = n-1;
    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--)
    {
        if (abs(arr[left]) > abs(arr[right]))
        {
            ans[i] = arr[left]*arr[left];
            left++;
        }
        else
        {
            ans[i] = arr[right]*arr[right];
            right--;
        }
    }
    return ans;
}

vector<vector<int>> diagonal(vector<vector<int> > &A) {
    int n = A.size();
    int N = 2*(n-1) + 1;
    vector<vector<int>> ans(N);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++){
            ans[i+j].push_back(A[i][j]);
        }
    }
    return ans;
}

void rotate(vector<vector<int> > &A) {
    int n = A.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(A[i][j] , A[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(A[i].begin() , A[i].end());
    }
}

int max_distance(vector<int> A){
    int n=A.size();
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(A[i],i));
    }
    sort(v.begin(),v.end());
    int ans=0;
    int rmax=v[n-1].second;
    for(int i=n-2;i>=0;i--){
        ans=max(ans,rmax-v[i].second);
        rmax=max(rmax,v[i].second);
    }
    return ans;
}

int minsteps(vector<int> a , vector<int> b){
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (abs(a[i] - a[i+1]) <= abs(b[i] - b[i+1]))
        {
            ans += (abs(b[i] - b[i+1]));
        }
        else
        {
            ans += (abs(a[i] - a[i+1]));
        }
    }
    return ans;
}

vector<vector<int>> spiralorder(int A){
    vector<vector<int>> a(A , vector<int>(A));
    int i, k = 0, l = 0;
    int c = 1;
    int m = A , n = A;
    while (k < m && l < n) {
        for (i = l; i < n; ++i) {
            a[k][i] = c;
            c++;
        }
        k++;
        for (i = k; i < m; ++i) {
            a[i][n-1] = c;
            c++;
        }
        n--;

        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                a[m-1][i] = c;
                c++;
            }
            m--;
        }

        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                a[i][l] = c;
                c++;
            }
            l++;
        }
    }
    return a;
}

vector<int> repeatandmissing(vector<int> v){
    int sum = 0;
    int squaresum = 0;
    int temp;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        sum -= (i+1);
        squaresum += v[i] * v[i];
        squaresum -= (i+1) * (i+1);
    }
    squaresum /= sum;
    int a = (squaresum+sum)/2;
    int b = squaresum - a;
    vector<int> ans;
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}

vector<vector<int>> pascalsTriangle(int n){
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

static bool cmp(int a , int b){
    string a1=to_string(a);
    string b1=to_string(b);
    return a1+b1 > b1+a1;
}

string largestNumber(vector<int> &a){
    vector<int> nums=a;
    int n=nums.size();
    sort(nums.begin(),nums.end(),cmp);
    string ans="";

    int c=0;
    for(int i=0;i<n;i++)
    {
        ans+= to_string(nums[i]);

        if(nums[i]==0)
        {
            c++;
        }
    }
    if(c==n)
    {
        return "0";
    }
    return ans;
}

int minnoofswaps(vector<int> v , int n){
    int ans = 0;
    vector<int> temp = v;
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] != temp[i])
        {
            ans++;
            int init = v[i];
            int k = mp[temp[i]];
            swap(v[i] , v[k]);
            mp[init] = k;
            mp[temp[i]] = i;
        }
    }
    return ans;
}

vector<int> subarrwithgivensum(int arr[] , int n , int s){
    int j = 0;
    int k = -1;
    int sum = 0;
    while (sum != s)
    {
        if (sum < s)
        {
            k++;
            sum += arr[k];
        }
        if (sum > s)
        {
            sum -= arr[j];
            j++;
        }
        if (sum < s && k < n)
        {
            break;
        }
    }
    if (sum == s)
    {
        if (k != -1)
        {
            return {j+1 , k+1};
        }
    }
    else
    {
        return {-1};
    }
    
}

vector<int> maxsubarr(int arr[] , int n){
    long long int s = 0 , sum = 0 , start = 0 , end = 0 , maxi = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
            start = s;
            end = i;
        }
        if (arr[i] == 0 && sum == maxi)
        {
            end++;
        }
        if (arr[i] < 0)
        {
            sum = 0;
            s = i+1;
        }
    }
    if (maxi > 0)
    {
        for (int i = start; i <= end; i++)
        {
            v.push_back(arr[i]);
        }
    }
    else
    {
        v.push_back(-1);
    }
    return v;
}

int main(){
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    move_negative_to_side(arr , 9);
    cout<<endl;
    int arr1[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    move_negative(arr1 , 9);
}