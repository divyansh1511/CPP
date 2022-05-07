#include<bits/stdc++.h>
using namespace std;

int uniquePath(int n , int m){
    vector<vector<int>> dp(n , vector<int>(m , 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n][m];
}

int main(){

}