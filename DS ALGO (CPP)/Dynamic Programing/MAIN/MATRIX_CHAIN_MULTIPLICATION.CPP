#include<bits/stdc++.h>
using namespace std;

//----------------------------RECURSION--------------------//

int helper(int i , int j , int arr[]){
    if (i == j)
    {
        return 0;
    }
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i-1]*arr[k]*arr[j] + helper(i , k , arr) + helper(k+1 , j , arr);
        if (steps < mini)
        {
            mini = steps;
        }
    }
    return mini;
}

int MCM(int arr[] , int n){
    return helper(1 , n-1 , arr);
}

//------------------------memoization-------------------------//

int MCMmemhelper(int i , int j , int arr[] , vector<vector<int>> &dp){
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i-1]*arr[k]*arr[j] + MCMmemhelper(i , k , arr , dp) + MCMmemhelper(k+1 , j , arr , dp);
        if (steps < mini)
        {
            mini = steps;
        }
    }
    return dp[i][j] = mini;
}

int MCMmem(int arr[] , int n){
    vector<vector<int>> dp(n , vector<int>(n , -1));
    return MCMmemhelper(1 , n-1 , arr , dp);
}

//-------------------------Tabulation-----------------------------//

int MCMtab(int arr[] , int n){
    int dp[n][n];
    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;  
    }
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = i+1; j < n; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                if (steps < mini)
                {
                    mini = steps;
                }
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}

int main(){

}