#include<bits/stdc++.h>
using namespace std;

int mincost(int cost[] , int n){
    if (n < 0)
    {
        return 0;
    }
    if (n == 0 || n == 1)
    {
        return cost[n];
    }
    return cost[n] + min(mincost(cost , n-1) , mincost(cost , n-2));
}

int mincostdp(int cost[] , int n){
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        if (i < 2)
        {
            dp[i] = cost[i];
        }
        else
        {
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
        }
    }
    return min(dp[n-1] , dp[n-2]);
}

int main(){

}