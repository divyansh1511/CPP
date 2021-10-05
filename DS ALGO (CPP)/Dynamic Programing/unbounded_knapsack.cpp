#include<iostream>
using namespace std;

int knapsackrec(int wt[] , int val[] , int W , int n){
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n-1] <= W)
    {
        return max(val[n-1] + knapsackrec(wt , val , W-wt[n-1] , n) , knapsackrec(wt , val , W , n-1));
    }
    else
    {
        return knapsackrec(wt , val , W , n-1);
    }
}

int knapsack(int wt[] , int val[] , int W , int n){
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i==0 || j == 0)
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
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]] , dp[i-1][j]);
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
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    cout<<knapsackrec(wt , val , W , 3)<<endl;
}