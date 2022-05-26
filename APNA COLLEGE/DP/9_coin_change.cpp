#include<bits/stdc++.h>
using namespace std;

int coinchange(vector<int> v , int val){
    int n = v.size();
    int dp[n+1][val+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= val; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = (j == 0) ? 0 : INT_MAX-1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= val; j++)
        {
            if (v[i] <= j)
            {
                dp[i][j] = min(dp[i-1][j] , dp[i][j-v[i-1]]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][val] == INT_MAX-1 ? -1 : dp[n][val];
}

int main(){

}