#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[] , int val[] , int n , int W){
    int dp[W+1];
    memset(dp , 0 ,sizeof(dp));
    for (int i = 0; i <= W; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (wt[j-1] <= i)
            {
                dp[i] = max(dp[i] , dp[i-wt[j]] + val[j]);
            }
        }
    }
    return dp[W];
}

int main(){

}