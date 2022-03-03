#include<bits/stdc++.h>
using namespace std;

//--------------------------knapsack 0 1 -------------------//

int knapsackrec(int wt[] , int val[] , int W , int n){
    if (W == 0 || n == 0)
    {
        return 0;
    }
    if (wt[n-1] <= W)
    {
        return max(knapsackrec(wt , val , W - wt[n-1] , n-1) + val[n-1] , knapsackrec(wt , val , W , n-1));
    }
    return knapsackrec(wt , val , W , n-1);
}

int knapsackmem(int wt[] , int val[] , int W , int n){
    static int dp[1002][1002];
    memset(dp , -1 , sizeof(dp));
    if (W == 0 || n == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (wt[n-1] <= W)
    {
        return dp[n][W] = max(val[n-1] + knapsackmem(wt , val , W-wt[n-1] , n-1) , knapsackmem(wt , val , W , n-1));
    }
    return dp[n][W] = knapsackmem(wt , val , W , n-1);
}

int knapsackdp(int wt[] , int val[] , int W , int n){
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

int main(){

}