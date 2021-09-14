#include<iostream>
using namespace std;

int solve(int arr[] , int n , int sum){
    int dp[n+1][sum+1];
    for (int i = 0; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
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
    int arr[] = {2,3,5,6,8,10};
    cout<<solve(arr , 6 , 10)<<endl;
}