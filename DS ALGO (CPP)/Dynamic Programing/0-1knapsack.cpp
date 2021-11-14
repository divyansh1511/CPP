#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[] , int prices[] , int W , int n){
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n-1] <= W)
    {
        return max(prices[n-1] +knapsack(wt , prices , W - wt[n-1] , n-1) , knapsack(wt , prices , W , n-1));
    }
    else
    {
        return knapsack(wt , prices , W , n-1);
    }
}

int knapsackmem(int wt[] , int prices[] , int W , int n){
    int static dp[1002][1002];
    memset(dp , -1 , sizeof(dp));
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    
    if (wt[n-1] <= W)
    {
        return dp[n][W] = max(prices[n-1] + knapsackmem(wt , prices , W-wt[n-1] , n-1) , knapsackmem(wt , prices , W , n-1));
    }
    else
    {
        return dp[n][W] = knapsackmem(wt , prices , W , n-1);
    }
}

int knapsackdp(int wt[] , int prices[] , int W , int n){
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
                dp[i][j] = max(prices[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(){
    int wt[] = {1,3,4,5};
    int prices[] = {1,4,5,7};
    cout<<knapsack(wt , prices , 7 , 4)<<endl;
    cout<<knapsackmem(wt , prices , 7 , 4)<<endl;
    cout<<knapsackdp(wt , prices , 7 , 4)<<endl;
}