#include<bits/stdc++.h>
using namespace std;

int maxnonnegativeproduct(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<long long>> mn(n , vector<long long>(m)) , mx(n , vector<long long>(m));
    mn[0][0] = mx[0][0] = grid[0][0];
    for (int i = 1; i < n; i++)
    {
        mn[i][0] = mx[i][0] = grid[i][0]*mx[i-1][0];
    }
    for (int i = 1; i < m; i++)
    {
        mn[0][i] = mx[0][i] = grid[0][i]*mx[0][i-1];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (grid[i][j] < 0)
            {
                mx[i][j] = min(mn[i-1][j] , mn[i][j-1]) * grid[i][j];
                mn[i][j] = max(mx[i-1][j] , mx[i][j-1]) * grid[i][j];
            }
            else
            {
                mx[i][j] = max(mx[i-1][j] , mx[i][j-1]) * grid[i][j];
                mn[i][j] = min(mn[i-1][j] , mn[i][j-1]) * grid[i][j];
            }
        }
    }
    int ans = mx[m-1][n-1];
    return ans < 0 ? -1 : ans;
}

int main(){

}