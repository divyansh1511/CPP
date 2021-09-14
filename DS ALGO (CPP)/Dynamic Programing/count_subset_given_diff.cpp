#include<iostream>
using namespace std;

int countsubsetsum(int arr[] , int n , int sum){
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
        for (int j = 1; j <=  sum; j++)
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

int solve(int arr[] , int n , int diff){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int sum1 = (diff+sum)/2;
    return countsubsetsum(arr , n , sum1);
}

int main(){
    int arr[] = {1,1,2,3};
    cout<<solve(arr , 4 , 1)<<endl;
}