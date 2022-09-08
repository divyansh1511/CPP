#include<bits/stdc++.h>
using namespace std;

void SetMatrix(vector<vector<int>> &v){
    bool firstrow = false;
    bool firstcol = false;
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        if (v[0][i] == 0)
        {
            firstcol = true;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (v[i][0] == 0)
        {
            firstrow = true;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                v[i][0] = 0;
                v[0][j] = 0;
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

vector<vector<int>> PascalsTriangle(int n){
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i].resize(i+1);
        ans[i][0] = ans[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }
    return ans;
}

void NextPermuatation(vector<int> &v){
    int k,l;
    int n = v.size();
    for(k=n-2;k>=0;k--){
        if (v[k] > v[k+1])
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
        for(l=n-1;l>=k;l--){
            if (v[l] > v[k])
            {
                break;
            }
        }
        swap(v[l] , v[k]);
        reverse(v.begin()+k+1 , v.end());
    }
}

int maxsubarrsum(int arr[] , int n){
    int currsum = 0;
    int maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        maxsum = max(maxsum , currsum);
        if (currsum < 0)
        {
            currsum = 0;
        }
    }
    return maxsum;
}

void sort012(vector<int> &v){
    int zeros = 0 , ones = 0 , twos = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
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
    int i = 0;
    for (i = 0; i < zeros; i++)
    {
        v[i] = 0;
    }
    for (i; i < (zeros+ones); i++)
    {
        v[i] = 1;
    }
    for (i; i < n; i++)
    {
        v[i] = 2;
    }
}

int bestTimetobuyandsell(int arr[] , int n){
    int minval = INT_MAX;
    int maxval = 0;
    for (int i = 0; i < n; i++)
    {
        minval = min(minval , arr[i]);
        maxval = max(maxval , arr[i]-minval);
    }
    return maxval;
}

void rotatematrix(vector<vector<int>> &v){
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; i++)
        {
            swap(v[i] , v[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(v[i].begin() , v[i].end());
    }
}

vector<vector<int>> mergeIntervals(vector<vector<int>> v){
    vector<vector<int>> ans;
    if (v.size() == 0)
    {
        return ans;
    }
    sort(v.begin() , v.end());
    ans.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        if (ans[ans.size()-1][1] >= v[i][0])
        {
            ans[ans.size()-1][1] = max(ans[ans.size()-1][1] , v[i][1]);
        }
        else
        {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

void merge2arr(int arr1[] , int n , int arr2[] , int m){
    int i = 0 , j = 0;
    int k = n-1;
    while (i<=k && j < m)
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

int findDuplicate(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        int ind = arr[i] - 1;
        arr[ind] *= -1;
        if (arr[ind] > 0)
        {
            return abs(arr[i]);
        }
    }
    return -1;
}

vector<int> repeat_ans_missing_no(int arr[] , int n){
    int sum = 0;
    int squaresum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        sum -= (i+1);
        squaresum += (arr[i]*arr[i]);
        squaresum -= ((i+1)*(i+1));
    }
    squaresum /= sum;
    int a = (sum+squaresum)/2;
    int b = squaresum - a;
    return {a,b};
}

int mergesorthelper(int arr[] , int temp[] , int left , int mid , int right){
    int c = 0;
    int i = left;
    int j = mid;
    int k = left;
    while (i <= mid-1 && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            c += (mid-i);
        }
    }
    while (i <= mid-1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    return c;
}

int mergesort(int arr[] , int temp[] , int i , int j){
    int mid , invcount = 0;
    if (j > i)
    {
        mid = (i+j)/2;
        invcount += mergesort(arr , temp , i , mid);
        invcount += mergesort(arr , temp , mid+1 , j);
        invcount += mergesorthelper(arr , temp , i , mid , j);
    }
    return invcount;
}

int countinversion(int arr[] , int n){
    int temp[n];
    return mergesort(arr , temp , 0 , n-1);
}

bool searchMatrix(vector<vector<int>> matrix , int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int lo = 0 , hi =  n*m-1;
    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        int x = mid/m;
        int y = mid%m;
        if (matrix[x][y] == target)
        {
            return true;
        }
        else if (matrix[x][y] < target)
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

double powofx(double x , int n){
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

int majority_element(int arr[] , int n){
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

int majority_element_2(int arr[] , int n){
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for(auto it : mp){
        if (it.second > n/3)
        {
            return it.first;
        }
    }
    return -1;
}

int grid_unique_path(int n , int m){
    vector<vector<int>> dp(n , vector<int>(m , 1));
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}

void checkcount(vector<int> &nums , int i , int mid , int j , int &count){
    int l = i , r = mid+1;
    while (l <= mid && r <= j)
    {
        if (nums[l] > 2*nums[r])
        {
            count += (mid-l+1);
            r++;
        }
        else
        {
            l++;
        }
    }
    sort(nums.begin()+i , nums.begin()+j+1);
}

void mergesortreve(vector<int> &nums , int i , int j , int &count){
    if (i == j)
    {
        return;
    }
    int mid = (i+j)/2;
    mergesortreve(nums , i , mid , count);
    mergesortreve(nums , mid , j , count);

    checkcount(nums , i , mid , j , count);
}

int reversePairs(vector<int> &nums){
    if (nums.size() == 0)
    {
        return 0;
    }
    int count = 0;
    mergesortreve(nums , 0 , nums.size()-1 , count);
    return count;
}

vector<int> TwoSum(int arr[] , int n , int target){
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(target - arr[i]) != mp.end())
        {
            return {mp[target - arr[i]] , i};
        }
        mp[arr[i]] = i;
    }
    return {-1};
}

vector<vector<int>> FourSum(vector<int> nums , int target){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for(int i=0; i<n-3; i++)
    {
        if(i == 0 || (i>0 && nums[i] != nums[i-1]))
        {
            for(int j=i+1; j<n-2; j++)
            {
                if(j == i+1 || (j>i+1 && nums[j] != nums[j-1]))
                {
                    int low = j+1, high = n-1;
                    long sum = long(target) - nums[i] - nums[j];
                    while(low<high)
                    {
                        if(nums[low] + nums[high] == sum)
                        {
                            vector<int> arr;
                            arr.push_back(nums[i]);
                            arr.push_back(nums[j]);
                            arr.push_back(nums[low]);
                            arr.push_back(nums[high]);
                            ans.push_back(arr);
                            while(low<high && nums[low] == nums[low+1])
                                low++;
                            while(low<high && nums[high] == nums[high-1])
                                high--;

                            low++;
                            high--;

                        }
                        else if(nums[low] + nums[high] < sum)
                            low++;
                        else 
                            high--;
                    }
                }
            }
        }
    }
    return ans;
}

int longestConsequtiveSequence(vector<int> nums){
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    int sum = 1;
    int maxans = 0;
    sort(nums.begin() , nums.end());
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i-1])
        {
            continue;
        }
        if (nums[i] != nums[i-1]+1)
        {
            maxans = max(sum , maxans);
        }
        else
        {
            sum++;
        }
    }
    return max(sum , maxans);
}

int LargestSubarrwithzerosum(vector<int> v){
    int n = v.size();
    unordered_map<int,int> mp;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum == 0)
        {
            ans = max(ans , i+1);
        }
        else if (mp.find(sum) != mp.end())
        {
            ans = max(ans , i-mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return ans;
}

int subarrwithgivenxor(vector<int> v , int xorr){
    int n = v.size();
    int ans = 0;
    int a = 0;
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        a ^= v[i];
        int t = a ^ xorr;
        ans += mp[t];
        if (a == xorr)
        {
            ans++;
        }
        mp[a]++;
    }
    return ans;
}

int longestsubstringwithoutrepeat(string s){
    vector<int> v(256 , -1);
    int left = 0;
    int right = 0;
    int len = 0;
    int n = s.length();
    while (right < n)
    {
        if (s[right] != -1)
        {
            left = max(left , v[s[right]]+1);
        }
        v[s[right]] = right;
        len = max(len , right-left+1);
        right++;
    }
    return len;
}

vector<vector<int>> ThreeSum(vector<int> v){
    sort(v.begin() , v.end());
    vector<vector<int>> ans;
    int n = v.size();
    for (int i = 0; i < n-2; i++)
    {
        if (i > 0 && v[i] == v[i-1])
        {
            continue;
        }
        int j = i+1 , k = n-1;
        while (j < k)
        {
            int sum = v[i] + v[j] + v[k];
            if (sum == 0)
            {
                ans.push_back({v[i] , v[j] , v[k]});
                while (j < k && v[j] == v[j+1])
                {
                    j++;
                }
                while (j < k && v[k] == v[k-1])
                {
                    k--;
                }
                j++;
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return ans;
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

int removeDuplicates(vector<int> arr){
    int i = 0;
    for(int n : arr){
        if (!i && n > arr[i-1])
        {
            arr[i++] = n;
        }
    }
    return i;
}

int maxconsequtiveones(vector<int> arr){
    int curr = 0;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            ans = max(ans , curr);
            curr = 0;
        }
        else
        {
            curr++;
        }
    }
    ans = max(ans , curr);
    return ans;
}

int main(){
    vector<vector<int>> v = {{1,1,1} , {1,0,1} , {1,1,1}};
    SetMatrix(v);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}