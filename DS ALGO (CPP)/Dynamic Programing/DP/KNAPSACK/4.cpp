#include<bits/stdc++.h>
using namespace std;

int countsubset(int arr[] , int n , int sum){
    if (n == 0 && sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (sum == 0)
    {
        return 1;
    }
    if (arr[n-1] <= sum)
    {
        return countsubset(arr , n-1 , sum) + countsubset(arr , n-1 , sum-arr[n-1]);
    }
    else
    {
        return countsubset(arr , n-1 , sum);
    }
}

int countsubsetdp(int arr[] , int n , int sum){
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

int main(){

}