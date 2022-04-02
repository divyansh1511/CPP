#include<bits/stdc++.h>
using namespace std;

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

int targetsum(int arr[] , int n , int target){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int sum1 = (sum+target)/2;
    if (sum < target || (sum+target)%2 != 0)
    {
        return 0;
    }
    return countsubsetdp(arr , n , sum1);
}

int main(){

}