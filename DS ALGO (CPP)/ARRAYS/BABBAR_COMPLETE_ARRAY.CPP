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
    int minele = INT_MAX;
    int maxele = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        minele = min(minele , arr[i]);
        maxele = max(maxele , arr[i]);
    }
    cout<<minele<<" "<<maxele<<endl;
}

void kthmaxele(int arr[] , int n , int k){
    priority_queue<int , vector<int> , greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    cout<<pq.top()<<endl;
}

void sort012(int arr[] , int n){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    for (int i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }
    for (int i = count0; i < (count0+count1); i++)
    {
        arr[i] = 1;
    }
    for (int i = (count0+count1); i < n; i++)
    {
        arr[i] = 2;
    }
}

void negative_to_side(int arr[] , int n){
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
}

void unionofarr(int arr1[] , int arr2[] , int n , int m){
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s.insert(arr2[i]);
    }
    for (auto it : s)
    {
        cout<<it<<" ";
    }
}

void intersection(int arr1[] , int arr2[] , int n , int m){
    sort(arr1 , arr1+n);
    sort(arr2 , arr2+m);
    vector<int> v;
    int i = 0 , j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            v.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    for (int k = 0; k < v.size(); k++)
    {
        cout<<v[k]<<" ";
    }
}

void helper(int arr[] , int n){
    int i = 0 , j = n-1;
    while (i < j)
    {
        swap(arr[i] , arr[j]);
        i++;
        j--;
    }
}

void rotatearr(int arr[] , int n , int d){
    helper(arr , n);
    helper(arr+n-d , d);
    helper(arr , n-d);
}

int maxsubarrsum(int arr[] , int n){
    int maxsum = 0;
    int currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        if (currsum < 0)
        {
            currsum = 0;
        }
        maxsum = max(maxsum , currsum);
    }
    return maxsum;
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
    int steps = arr[0];
    int jumps = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n-1)
        {
            return jumps;
        }
        maxreach = max(maxreach , i+arr[i]);
        steps--;
        if (steps == 0)
        {
            jumps++;
            if (i >= maxreach)
            {
                return -1;
            }
            steps = maxreach - i;
        }
    }
    return -1;
}

int find_duplicate(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]) - 1;
        arr[index] *= -1;
        if (arr[index] > 0)
        {
            return abs(arr[i]);
        }
    }
    return -1;
}

void merge2arr(int arr1[] , int arr2[] , int n , int m){
    int i = 0 , j = 0 , k = n-1;
    while (i < k && j < m)
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
            continue;
        }
    }
    sort(arr1 , arr1+n);
    sort(arr2 , arr2+m);
}

vector<vector<int>> mergeinterval(vector<vector<int>> intervals){
    vector<vector<int>> ans;
    if (intervals.size() == 0)
    {
        return ans;
    }
    sort(intervals.begin() , intervals.end());
    ans.push_back(intervals[0]);
    int j = 0;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (ans[j][1] >= intervals[i][0])
        {
            ans[j][1] = max(ans[j][1] , intervals[i][1]);
        }
        else
        {
            j++;
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}

void nextpermutation(int arr[] , int n){
    int l,k;
    for (k = n-2; k >= 0; k--)
    {
        if (arr[k] < arr[k+1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(arr , arr+n);
    }
    else
    {
        for (l = n-1; l > k ; l--)
        {
            if (arr[l] > arr[k])
            {
                break;
            }
        }
        swap(arr[l] , arr[k]);
        reverse(arr+k+1 , arr+n);
    }
}

vector<int> commoneleinThree(int arr1[] , int arr2[] , int arr3[] , int n1 , int n2 , int n3){
    unordered_set<int> s1,s2,s3;
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
        if(s1.find(arr3[i])!=s1.end() && s2.find(arr3[i])!=s2.end()){
            if(s3.find(arr3[i])==s3.end()){
                v.push_back(arr3[i]);
            }
            s3.insert(arr3[i]);
        }
    }
    return v;
}

bool subarrwithsumK(int arr[] , int n , int k){
    unordered_set<int> s;
    int sum = 0;
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

int maxproductval(int arr[] , int n){
    int minval = arr[0];
    int maxval = arr[0];

    int maxpro = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(minval , maxval);
        }
        maxval = max(maxval , maxval*arr[i]);
        minval = min(minval , minval*arr[i]);

        maxpro = max(maxpro , maxval);
    }
    return maxpro;
}

bool find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;
    sort(A, A + arr_size);
    for (int i = 0; i < arr_size - 2; i++) {
        l = i + 1; 
        r = arr_size - 1; 
        while (l < r) {
            if (A[i] + A[l] + A[r] == sum) {
                printf("Triplet is %d, %d, %d", A[i],
                       A[l], A[r]);
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else 
                r--;
        }
    }
    return false;
}

long long trappingWater(int arr[], int n){
    int left[n];
    int right[n];
    long long water = 0;
    left[0] = arr[0];
    for(int i=1;i<n;i++){
        left[i] = max(left[i-1] , arr[i]);
    }
    right[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        right[i] = max(right[i+1] , arr[i]);
    }
    for(int i=0;i<n;i++){
         water += min(left[i] , right[i]) - arr[i];
    }
    return water;
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

int main(){
    // int n;
    // cin>>n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>arr[i];
    // }
    // reversearr(arr , n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // min_max(arr , n);
    // kthmaxele(arr , n , 2);
    // sort012(arr , n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // negative_to_side(arr , n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // int arr1[] = {12,4,3,5,6,72};
    // int arr2[] = {4,6,8,10,12};
    // unionofarr(arr1 , arr2 , 6 , 5);
    // cout<<endl;
    // intersection(arr1 , arr2 , 6 , 5);
    // int arr[] = {1,-3,3,-2,5};
    // cout<<maxsubarrsum(arr , 5)<<endl;
    // int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6};
    // cout<<minjumps(arr , 11)<<endl;
    // cout<<find_duplicate(arr , 9)<<endl;
    // int arr1[] = {1,3,5,7,9};
    // int arr2[] = {2,4,6,8};
    // merge2arr(arr1 , arr2 , 5 , 4);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<arr1[i]<<" ";
    // }
    // for (int i = 0; i < 4; i++)
    // {
    //     cout<<arr2[i]<<" ";
    // }
    
}