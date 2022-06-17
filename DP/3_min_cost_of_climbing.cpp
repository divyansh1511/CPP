#include<bits/stdc++.h>
using namespace std;

int mincost(int arr[] , int n){
    int dp[n+1];
    memset(dp , 0 , sizeof(dp));
    for (int i = 2; i <= n; i++)
    {
        int onestep = dp[i-1] + arr[i-1];
        int twostep = dp[i-2] + arr[i-2];
        dp[i] = min(onestep , twostep);
    }
    return dp[n];
}

int main(){

}