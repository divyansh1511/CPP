#include<bits/stdc++.h>
using namespace std;

bool subsetsumpr(int arr[] , int n , int sum){
    if (n == 0 && sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (sum == 0)
    {
        return true;
    }
    if (arr[n-1] <= sum)
    {
        return subsetsumpr(arr , n-1 , sum-arr[n-1]) || subsetsumpr(arr , n-1 , sum);
    }
    else
    {
        return subsetsumpr(arr , n-1 , sum);
    }
}

int subsetsumprdp(int arr[] , int n , int sum){
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

int main(){

}