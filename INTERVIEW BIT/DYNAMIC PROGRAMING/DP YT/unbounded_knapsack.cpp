#include<bits/stdc++.h>
using namespace std;

//------------------------------unbounded_knapsack--------------------//

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
            if(wt[i-1] <= j){
                dp[i][j] = max(dp[i][j-wt[i-1]] + val[i-1], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

//-------------------------ROD CUTTING-------------------------------//

int rodcutting(int len[] , int prices[] , int n , int length){
    int dp[n+1][length+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= length; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= length; i++)
        {
            if (len[i-1] <= j)
            {
                dp[i][j] = max(prices[i-1] + dp[i][length-len[i-1]] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][length];
}

//-------------------------------------COIN CHANGE --- NUMBER OF WAYS-------------------------

int coinchange(int arr[] , int n , int m){
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
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
    return dp[n][m];
}

int main(){

}