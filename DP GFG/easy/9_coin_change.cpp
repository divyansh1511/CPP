//---------------------------MAX NUMBER OF WAYS-----------------------//
#include<bits/stdc++.h>
using namespace std;

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

int main(){
    int arr[] = {1,2,3};
    cout<<coinchange(arr , 3 , 4)<<endl;
}