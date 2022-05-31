#include<bits/stdc++.h>
using namespace std;

int perfectsquares(int n){
    int dp[n+1];
    memset(dp , INT_MAX , sizeof(dp));
    dp[0] = 0;
    int count = 1;
    while (count*count <= n)
    {
        int sq = count*count;
        for (int i = sq; i <= n; i++)
        {
            dp[i] = min(dp[i] , dp[i-sq]+1);
        }
        count++;
    }
    return dp[n];
}

int maiin(){

}