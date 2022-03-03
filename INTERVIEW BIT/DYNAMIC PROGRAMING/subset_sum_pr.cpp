#include<bits/stdc++.h>
using namespace std;

bool subsetsumproblem(int arr[] , int n , int W){
    if (W == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (arr[n-1] <= W)
    {
        return subsetsumproblem(arr , n-1 , W-arr[n-1]) || subsetsumproblem(arr , n-1 , W);
    }
    return subsetsumproblem(arr , n-1 , W);
}

bool subsetsumprDP(int arr[] , int n , int W){
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 0; i <= W; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; i++)
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
    return dp[n][W];
}

int main(){

}