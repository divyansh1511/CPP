#include<bits/stdc++.h>
using namespace std;

//----------------------------------------0 - 1 KNAPSACK-------------------------------------------//

int knapsackrec(int wt[] , int val[] , int w , int n){
    if (w == 0 || n == 0)
    {
        return 0;
    }
    if (wt[n-1] <= w)
    {
        return max(knapsackrec(wt , val , w - wt[n-1] , n-1)+val[n-1] , knapsackrec(wt,val , w , n-1));
    }
    else
    {
        return knapsackrec(wt , val , w , n-1);
    }
}

int knapsackdp(int wt[] , int val[] , int w , int n){
    int dp[n+1][w+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i-1] <= j)
            {
                dp[i][j] = max(dp[i-1][j-wt[i-1]] + val[i-1], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

bool subsetsumpr(int arr[] , int n , int sum){
    int dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int equalsumpartition(int arr[] , int n ){
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += arr[i];
    }
    if (sum%2 != 0)
    {
        return false;
    }
    return subsetsumpr(arr , n , sum/2);
}

int countsubset(int arr[] , int n , int sum){
    int dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int countsubsetdiff(int arr[] , int n , int diff){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int sum1 = (sum+diff)/2;
    return countsubset(arr , n , sum1);
}

int targetsum(int arr[] , int n , int target){
    target = abs(target);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int sum1 = (sum+target)/2;
    if (sum < target || (sum+target)%2 != 0)
    {
        return 0;
    }
    return countsubsetdiff(arr , n , sum1);
}

//---------------------------------------Unbounded KNAPSACK---------------------------------//

int unboundedknapsack(int wt[] , int val[] , int w , int n){
    if (w == 0 || n == 0)
    {
        return 0;
    }
    if (wt[n-1] <= w)
    {
        return max(unboundedknapsack(wt , val , w-wt[n-1] , n) + val[n-1] , unboundedknapsack(wt , val , w , n-1));
    }
    else
    {
        return unboundedknapsack(wt , val , w , n-1);
    }
}

int unboundedknapsackdp(int wt[] , int val[] , int w , int n){
    int dp[n+1][w+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i-1] <= j)
            {
                dp[i][j] = max(dp[i][j-wt[i-1]] + val[i-1] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int rodcutting(int length[] , int prices[] , int n , int len){
    int dp[n+1][len+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            if (length[i-1] <= j)
            {
                dp[i][j] = max(dp[i][j-length[i-1]] + prices[i-1] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][len];
}

int coinchange_noofways(int arr[] , int n , int sum){
    int dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i-1] <= j)
            {
                dp[i][j] = dp[i][j-arr[i-1]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int coinchange_minnoofcoins(int arr[] , int n , int sum){
    int dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i-1] <= j)
            {
                dp[i][j] = min(dp[i][j-arr[i-1]] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

//--------------------------------------------STRINGS------------------------------------//

int longestCommonSubsequence(string a , string b , int n , int m){
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (a[n-1] == b[m-1])
    {
        return 1 + longestCommonSubsequence(a , b , n-1 , m-1);
    }
    else
    {
        return max(longestCommonSubsequence(a,b,n-1,m) , longestCommonSubsequence(a,b,n,m-1));
    }
}

int lcsdp(string a , string b , int n , int m){
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i-1] == b[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int longestCommonSubstring(string a , string b , int n , int m){
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                res = max(res , dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return res;
}

int longestPalindromeSubsequence(string a , int n){
    string b = a;
    reverse(b.begin() , b.end());
    return lcsdp(a , b , n , n);
}

int minnoofdeletiontopalindrome(string s , int n){
    return  n - longestPalindromeSubsequence(s , n);
}

string shortestCommonSupersequence(string a , string b , int n , int m){
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i-1] == b[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    int i = n , j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (a[i-1] == b[j-1])
        {
            ans += a[i-1];
            i--;
            j--;
        }
        else
        {
            if (dp[i-1][j] < dp[i][j-1])
            {
                ans += b[i-1];
                j--;
            }
            else
            {
                ans += a[i-1];
                i--;
            }
        }
    }
    return ans;
}

int longestrepeatingsequence(string a , int n){
    int dp[n+1][n+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i-1] == a[j-1] && i != j)
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

//-----------------------------INCREASING SUBSEQUENCE------------------------//

int longestIncreasingSubsequence(int arr[] , int n){
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j]+1)
            {
                lis[i] = lis[j]+1;
            }
        }
    }
    return *max_element(lis , lis+n);
}

int maxsumofIncreasingSequence(int arr[] , int n){
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j]+arr[i])
            {
                lis[i] = lis[j]+arr[i];
            }
        }
    }
    return *max_element(lis , lis+n);
}

int maxproofIncreasingSequence(int arr[] , int n){
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j]*arr[i])
            {
                lis[i] = lis[j]*arr[i];
            }
        }
    }
    return *max_element(lis , lis+n);
}

//---------------------------------MATRIX CHAIN MULTIPLICATION----------------------//

int helper(int i, int j, int arr[])
{
    if (i == j)
    {
        return 0;
    }
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + helper(i, k, arr) + helper(k + 1, j, arr);
        if (steps < mini)
        {
            mini = steps;
        }
    }
    return mini;
}

int MCM(int arr[], int n)
{
    return helper(1, n - 1, arr);
}

int MCMtab(int arr[], int n)
{
    int dp[n][n];
    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                if (steps < mini)
                {
                    mini = steps;
                }
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n - 1];
}

int main(){

}