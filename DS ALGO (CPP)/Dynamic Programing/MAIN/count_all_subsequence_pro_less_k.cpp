#include<bits/stdc++.h>
using namespace std;

int noofsubsequence(vector<int> arr , int k){
    int n = arr.size();
    int dp[n+1][k+1];
    memset(dp , 0 , sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j)
            {
                dp[i][j] += dp[i-1][j/arr[i-1]] + 1;
            }
        }
    }
    return dp[n][k];
}

int main(){
    vector<int> arr = {4,8,7,2};
    cout<<noofsubsequence(arr , 50)<<endl;
}