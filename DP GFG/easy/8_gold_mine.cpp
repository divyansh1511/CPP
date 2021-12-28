#include<bits/stdc++.h>
using namespace std;

int goldmine(int arr[][1000], int n, int m){
    int dp[n+1][m+1];
    memset(dp , 0 ,sizeof(dp));

    for (int i = m-1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            int right = (i == m-1) ? 0 : dp[j][i+1];
            int right_up = (j == 0 || i == m-1) ? 0 : dp[j-1][i+1];
            int right_down = (j == n-1 || i == m-1) ? 0 : dp[j+1][i+1];
            dp[j][i] = arr[j][i] + max({right , right_up , right_down});
        }
    }
    int res = dp[0][0];
    for (int i = 0; i < n; i++)
    {
        res = max(res , dp[i][0]);
    }
    return res;
}

int main(){
    int arr[][1000] = {{1,3,3} , {2,1,4} , {0,6,4}};
    cout<<goldmine(arr , 3 , 3)<<endl;
}