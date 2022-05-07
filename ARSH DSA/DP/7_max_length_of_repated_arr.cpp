#include<bits/stdc++.h>
using namespace std;

int maxlength(int arr1[] , int arr2[] , int n , int m){
    int dp[n+1][m+1];
    int ans = 0;
    memset(dp , 0 , sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr1[i-1] == arr2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
                ans = max(ans , dp[i][j]);
            }
        }
    }
    return ans;
}

int main(){

}