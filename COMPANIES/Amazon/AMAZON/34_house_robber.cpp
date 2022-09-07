#include<bits/stdc++.h>
using namespace std;

int house_robber(vector<int> arr){
    int n = arr.size();
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return arr[0];
    }
    if (n == 2)
    {
        return max(arr[0] , arr[1]);
    }
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0] , arr[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i-2] + arr[i] , dp[i-1]);
    }
    return dp[n-1];
}

int main(){

}