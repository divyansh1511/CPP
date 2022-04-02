#include<bits/stdc++.h>
using namespace std;

int cointchange(int arr[] , int n , int sum){
    if (n == 0 || sum == 0)
    {
        return sum == 0 ? 0 : INT_MAX - 1;
    }
    if (arr[n-1] <= sum)
    {
        return min(cointchange(arr , n , sum-arr[n-1]) + 1 , cointchange(arr , n-1 , sum));
    }
    else
    {
        return cointchange(arr , n-1 , sum);
    }
}

int coinchangeDp(int arr[] , int n , int sum){
    int dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = j == 0 ? 0 : INT_MAX-1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i-1] <= j)
            {
                dp[i][j] = min(dp[i-1][j] , dp[i][j-arr[i-1]]+1);
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
    int arr[] = {1,2,5};
    cout<<cointchange(arr , 3 , 11)<<endl;
    cout<<coinchangeDp(arr , 3 , 11)<<endl;
}