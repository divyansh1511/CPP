#include<bits/stdc++.h>
using namespace std;

void printarr(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//-------------------------------1st-------------------------//

void reversearr(int arr[] , int n){
    int i = 0 , j = n-1;
    while (i < j)
    {
        swap(arr[i] , arr[j]);
        i++;
        j--;
    }
}

//-------------------------------2nd--------------------------//

int maxsubarrsum(int arr[] , int n){
    int maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        int currsum = arr[i];
        for (int j = i+1; j < n; j++)
        {
            currsum += arr[j];
            if (maxsum < currsum)
            {
                maxsum = currsum;
            }
        }
    }
    return maxsum;
}

int maxsubarrsumopti(int arr[] , int n){
    int maxsum = 0;
    int currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        if (currsum < 0)
        {
            currsum = 0;
        }
        maxsum = max(currsum , maxsum);
    }
    return maxsum;
}

//--------------------------------3rd---------------------------------//

int minjumps(int arr[] , int n){
    if (n <= 1)
    {
        return 0;
    }
    if (arr[0] == 0)
    {
        return -1;
    }
    int steps = arr[0];
    int maxreach = arr[0];
    int jumps = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n-1)
        {
            return jumps;
        }
        maxreach = max(maxreach , maxreach + i);
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
    return -1;
}

//--------------------------------4th---------------------------//

vector<vector<int>> mergeintervals(vector<vector<int>> v){
    sort(v.begin() , v.end());
    vector<vector<int>> ans;
    ans.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        int n = ans.size();
        if (ans[n-1][1] > v[i][0])
        {
            ans[n-1][1] = max(ans[n-1][1] , v[i][1]);
        }
        else
        {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

//-------------------------------------5th--------------------------//

void merge2arr(int arr1[] , int arr2[] , int n , int m){
    int i = 0 , j = 0 , k = n-1;
    while (i < k && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr2[j] , arr1[k]);
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

//------------------------------------6th--------------------------//

void nextpermutation(int arr[] , int n){
    int k , l;
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
        for (l = n-1; l >= k; l--)
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

//------------------------------------7th----------------------//

int trappingrainwater(int arr[] , int n){
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
        right[i] = max(arr[i] , right[i+1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (min(left[i] , right[i]) - arr[i]);
    }
    return ans;
}

int trappingrainwateropti(int arr[] , int n){
    int i = 0 , j = n-1;
    int leftmax = arr[i] , rightmax = arr[j];
    int ans = 0;
    while (i <= j)
    {
        if (arr[i] < arr[j])
        {
            if (leftmax < arr[i])
            {
                leftmax = arr[i];
            }
            else
            {
                ans = ans + (leftmax - arr[i]);
            }
            i++;
        }
        else
        {
            if (rightmax < arr[j])
            {
                rightmax = arr[j];
            }
            else
            {
                ans = ans + (rightmax - arr[i]);
            }   
            j--;
        }
    }
    return ans;
}

//--------------------------------8th-----------------------------//

void setmatrixzero(vector<vector<int>> v){
    bool firstrow = false;
    bool firstcol = false;
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        if (v[i][0] == 0)
        {
            firstrow = true;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (v[0][i] == 0)
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
        for (int i = 0; i < n; i++)
        {
            v[i][0] = 0;
        }
    }
    if (firstcol)
    {
        for (int i = 0; i < m; i++)
        {
            v[0][i] = 0;
        }
    }
}

//-----------------------------------9th----------------------------------//

int findmissingno(int arr[] , int n){
    int i = 0;
    while (i < n)
    {
        if (arr[i] > 0 && arr[i] <= n)
        {
            int pos = arr[i] - 1;
            if (arr[pos] != arr[i])
            {
                swap(arr[pos] , arr[i]);
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != (i+1))
        {
            return i+1;
        }
    }
    return n+1;
}

//--------------------------------------10th------------------------------------//

vector<int> sortwithsquares(vector<int> v){
    int n = v.size();
    vector<int> ans(n);
    int i = 0 , j = n-1;
    for (int k = n-1; k >= 0; k--)
    {
        if (abs(v[i]) > abs(v[j]))
        {
            ans[i] = v[i]*v[i];
            i++;
        }
        else
        {
            ans[i] = v[j]*v[j];
            j--;
        }
    }
    return ans;
}

//-----------------------------------11th---------------------------------//

vector<vector<int>> Antidiagonals(vector<vector<int>> v){
    int n = v.size();
    int N = 2*(n-1)+1;
    vector<vector<int>> ans(N);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i+j].push_back(v[i][j]);
        }
    }
    return ans;
}

//------------------------------------12th-----------------------------------//

void rotatematrix(vector<vector<int>> &v){
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(v[i][j] , v[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(v[i].begin() , v[i].end());
    }
}

//-----------------------------------13th----------------------------------//

int maxdistance(vector<int> v){
    int n = v.size();
    vector<pair<int,int>> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back({v[i] , i});
    }
    sort(ans.begin() , ans.end());
    int a = ans[n-1].second;
    int b = 0;
    for (int i = n-2; i >= 0; i--)
    {
        b = max(b , a - ans[i].second);
        a = max(a , ans[i].second);
    }
    return b;
}

//---------------------------------14th---------------------------------//

int MinStepsToInfiniteGrid(vector<int> a , vector<int> b){
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += max(abs(a[i] - a[i+1]) , abs(b[i] - b[i+1]));
    }
    return ans;
}

//--------------------------------15th---------------------------------//

vector<vector<int>> spiralordermatrix(int A){
    int i = 0 , j = 0 , k;
    int n = A , m = A;
    int c = 1;
    vector<vector<int>> arr(n , vector<int>(m));
    while (i < n && j < m)
    {
        for (k = j; k < m; k++)
        {
            arr[i][k] = c;
            c++;
        }
        i++;
        for (k = i; k < n; k++)
        {
            arr[k][m-1] = c;
            c++;
        }
        m--;
        if (i < n)
        {
            for (k = m-1; k >= j; k--)
            {
                arr[n-1][k] = c;
                c++;
            }
            n--;
        }
        if (j < m)
        {
            for (k = m-1; k >= i; k--)
            {
                arr[k][j] = c;
                c++;
            }
            j++;
        }
    }
    return arr;
}

//---------------------------------16th-----------------------------//

int balancearray(int arr[] , int n){
    int sum1 = 0 , sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            sum1 += arr[i];
        }
        else
        {
            sum2 += arr[i];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            sum1 -= arr[i];
            if (sum1 == sum2)
            {
                count++;
            }
            sum2 += arr[i];
        }
        else
        {
            sum2 -= arr[i];
            if (sum1 == sum2)
            {
                count++;
            }
            sum1 += arr[i];
        }
    }
    return count;
}

//------------------------------------17th------------------------------//

vector<int> addoneno(vector<int> v){
    reverse(v.begin() , v.end());
    vector<int> ans;
    int carry = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int sum = v[i] + carry;
        ans.push_back(sum%10);
        carry = sum/10;
    }
    while (carry > 0)
    {
        ans.push_back(carry%10);
        carry /= 10;
    }
    while (ans[ans.size() - 1] == 0 && ans.size() > 1)
    {
        ans.pop_back();
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

//-------------------------------------18th-----------------------------//

int maxabsolutediff(int arr[] , int n){
    int max1 = arr[0];
    int max2 = arr[0];
    int min1 = arr[0];
    int min2 = arr[0];
    for (int i = 0; i < n; i++)
    {
        max1 = max(max1 , arr[i]+i);
        max2 = max(max2 , arr[i]-i);
        min1 = min(min1 , arr[i]+i);
        min2 = min(min2 , arr[i]-i);
    }
    int ans = max(max1 - min1 , max2 - min2);
    return ans;
}

// MINIMISE THE HEIGHTS is similar to this.

//-----------------------------------19th-----------------------------//

bool tripletwithsum(vector<string> v){
    int n = v.size();
    sort(v.begin() , v.end());
    int i = 0 , j = n-1;
    while (i < j)
    {
        int mid = (i+j)/2;
        double a = stof(v[i]);
        double b = stof(v[mid]);
        double c = stof(v[j]);
        double sum = a+b+c;
        if (sum > 2)
        {
            j--;
        }
        else if(sum < 1){
            i++;
        }
        else{
            return true;
        }
    }
    return false;
}

//---------------------------------------20th-------------------------//

void movenegativetoleft(int arr[] , int n){
    int i = 0 , j = n-1;
    while (i <= j)
    {
        if (arr[i] < 0 && arr[j] < 0)
        {
            i++;
        }
        else if (arr[i] > 0 && arr[j] < 0)
        {
            swap(arr[i] , arr[j]);
            i++;
            j--;
        }
        else if (arr[i] > 0 && arr[j] > 0)
        {
            j--;
        }
        else
        {
            i++;
            j--;
        }
    }
}

//----------------------------------21th----------------------------//

int minstepsk(int arr[] , int n , int k){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < k)
        {
            count++;
        }
    }
    int bad = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > k)
        {
            bad++;
        }
    }
    int ans = bad;
    for(int i=0,j=count;j<n;i++,j++){
        if (arr[i] > k)
        {
            bad--;
        }
        if (arr[j] > k)
        {
            bad++;
        }
        ans = min(ans , bad);
    }
    return ans;
}

int main(){
    // int arr[] = {10,-20,30,40,-50,60};
    // printarr(arr , 6);
    // reversearr(arr , 6);
    // printarr(arr , 6);
    // cout<<maxsubarrsum(arr , 6)<<endl;
    // cout<<maxsubarrsumopti(arr , 6)<<endl;
    // int arr1[] = {1,3,2,4,1,5,7};
    // cout<<minjumps(arr1 , 7)<<endl;
    // vector<vector<int>> v = {{1,5} , {8 , 10} , {2,6} , {7 , 9}};
    // vector<vector<int>> ans = mergeintervals(v);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // int arr2[] = {1,3,5,7,9};
    // int arr3[] = {2,4,6,8};
    // merge2arr(arr2 , arr3 , 5 , 4);
    // printarr(arr2 , 5);
    // printarr(arr3 , 4);
    // int arr4[] = {1,2,3};
    // nextpermutation(arr4 , 3);
    // printarr(arr4 , 3);
    // int arr5[] = {3,0,3,1,2,4};
    // cout<<trappingrainwater(arr5 , 6)<<endl;
    // cout<<trappingrainwateropti(arr5 , 6)<<endl;
    // int arr[] = {3,4,-1,1};
    // cout<<findmissingno(arr , 4)<<endl;
    // vector<vector<int>> ans = spiralordermatrix(3);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}