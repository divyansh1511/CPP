#include<bits/stdc++.h>
using namespace std;

//------------------------------------KNAPSACK 0-1---------------------------------//

int knapsack(int wt[] , int val[] , int W , int n){
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i-1] <= j)
            {
                dp[i][j] = max(dp[i-1][j-wt[i-1]] + val[i-1] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

//---------------------------------------subset sum problem---------------------------//

bool subsetsumpr(int arr[] , int sum , int n){
    bool dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 0; i <= sum; i++)
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

//-----------------------------------EQUAL SUM PARTITION-----------------------------//

bool equalsumpartition(int arr[] , int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    return subsetsumpr(arr , sum/2 , n);
}

//----------------------------------COUNT SUBSET BY GIVEN SUM------------------------//

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

//--------------------------------------count of subset with given diff--------------------------//

int countsubsetdiff(int arr[] , int n , int diff){
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += arr[i];
    }
    int target = (sum+diff)/2;
    return countsubset(arr , n , target);
}

//-------------------------------------TARGET SUM--------------------------------//

int targetsum(int arr[] , int n , int tr){
    tr = abs(tr);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int sum1 = (sum+tr)/2;
    if (sum < tr || (sum + tr) % 2 != 0)
    {
        return 0;
    }
    return countsubset(arr , n , sum1);
}

int main(){

}