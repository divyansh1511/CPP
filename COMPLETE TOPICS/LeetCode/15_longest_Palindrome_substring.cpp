#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s){
    int n = s.length();
    int dp[n][n];
    memset(dp , 0 , sizeof(dp));
    int mxlen = 0 , start = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        mxlen = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[i+1])
        {
            dp[i][i+1] = 1;
            mxlen = 2;
            start = i;
        }
    }
    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n-k+1; i++)
        {
            int j = i+k-1;
            if (s[i] == s[j] && dp[i+1][j-1] == 1)
            {
                dp[i][j] = 1;
                if (k > mxlen)
                {
                    mxlen = k;
                    start = i;
                }
            }
        }
    }
    return s.substr(start , mxlen);
}

int main(){

}