#include<iostream>
using namespace std;

bool subsetsumpr(int arr[] , int n , int m){
    int dp[n+1][m+1];
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
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
    return dp[n][m];
}

int main(){
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (subsetsumpr(set, n, sum) == true)
         cout <<"Found a subset with given sum";
    else
        cout <<"No subset with given sum";
    return 0;
}