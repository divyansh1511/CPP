#include<bits/stdc++.h>
using namespace std;

int rodcutting(int length[] , int prices[] , int n , int len){
    int dp[n+1][len+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            if (length[i-1] <= j)
            {
                dp[i][j] = max(prices[i-1] + dp[i][j-length[i-1]] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][len];
}

int main(){

}