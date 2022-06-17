#include<bits/stdc++.h>
using namespace std;

int houseRobber(int arr[] , int n){
    int dp[n];
    memset(dp , 0 , sizeof(dp));
    dp[0] = arr[0];
    dp[1] = max(arr[0] , arr[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i-1] , dp[i-2]+arr[i]);
    }
    return dp[n-1];
}

int main(){

}