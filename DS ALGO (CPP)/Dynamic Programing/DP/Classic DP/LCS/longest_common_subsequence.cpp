#include<bits/stdc++.h>
using namespace std;

int lcsrec(string s1 , string s2 , int n , int m){
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (s1[n-1] == s2[m-1])
    {
        return 1+lcsrec(s1 , s2 , n-1 , m-1);
    }
    else
    {
        return max(lcsrec(s1 , s2 , n-1 , m) , lcsrec(s1 , s2 , n , m-1));
    }
}

int lcsdp(string s1 , string s2 , int n , int m){
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[i-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){

}