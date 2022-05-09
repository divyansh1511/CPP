#include<bits/stdc++.h>
using namespace std;

int maximalsquare(vector<vector<int>> grid){
    if (grid.size() == 0)
    {
        return 0;
    }
    int n = grid.size() , m = grid[0].size() , sz = 0;
    int dp[n][m];
    memset(dp , -1 , sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!i || !j || grid[i][j] == '0')
            {
                dp[i][j] = grid[i][j] - '0';
            }
            else
            {
                dp[i][j] = min({dp[i-1][j] , dp[i-1][j-1] , dp[i][j-1]}) + 1;
            }
            sz = max(sz , dp[i][j]);
        }
    }
    return sz*sz;
}

int main(){

}