#include<bits/stdc++.h>
using namespace std;

int knapsackrec(int wt[] , int val[] , int n , int W){
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n-1] <= W)
    {
        return max(knapsackrec(wt , val , n-1 , W-wt[n-1]) + val[n-1] , knapsackrec(wt , val , n-1 , W));
    }
    else
    {
        return knapsackrec(wt , val , n-1 , W);
    }
}

int knapsackdp(int wt[] , int val[] , int n , int W){
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
    int wt[] = {1,2,3,4,5};
    int val[] = {10,25,15,30,25};
    int W = 7;
    int n = 5;
    cout<<knapsackrec(wt , val , n , W)<<endl;
    cout<<knapsackdp(wt , val , n , W)<<endl;
}