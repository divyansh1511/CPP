#include<bits/stdc++.h>
using namespace std;

int unique_path(int n , int m){
    int dp[n][m];
    memset(dp , 1 , sizeof(dp));
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}

int main(){

}