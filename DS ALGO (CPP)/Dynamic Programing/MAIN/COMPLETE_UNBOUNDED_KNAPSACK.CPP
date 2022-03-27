#include<bits/stdc++.h>
using namespace std;

//---------------------------------------UNBOUNDED KNAPSACK-------------------------//

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

int knapsackmem(int wt[] , int val[] , int W , int n){
    static int dp[1002][1002];
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
        return dp[n][W] = max(val[n-1] + knapsackmem(wt , val , W - wt[n-1] , n) , knapsackmem(wt , val , W , n-1));
    }
    else
    {
        return dp[n][W] = knapsackmem(wt , val , W , n-1);
    }
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

//-------------------------------- ROD CUTTING PROBLEM -----------------------------//

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

//-------------------------------------------COIN - CHANGE PROBLEM -- MINIMUM NO OF COINS--------------------------

int coinchangemin(int coins[] , int n , int val){
    int dp[n+1][val+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= val; i++)
    {
        dp[0][i] = INT_MAX;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= val; j++)
        {
            if (coins[i-1] <= j)
            {
                dp[i][j] = min(dp[i][j-coins[i-1]] + 1 , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][val];
}

int main(){
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    cout<<knapsackrec(wt , val , W , 3)<<endl;
    cout<<knapsackmem(wt , val , W , 3)<<endl;
    cout<<knapsackdp(wt , val , W , 3)<<endl;
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = sizeof(price) / sizeof(price[0]);
    int length[n];
    for (int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    cout<<knapsackdp(length , price , n , n);
}