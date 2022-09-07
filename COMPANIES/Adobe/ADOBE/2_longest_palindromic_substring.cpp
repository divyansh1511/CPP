#include<bits/stdc++.h>
using namespace std;

string longestpalindromicsubstring(string s){
    int n = s.length();
    int dp[n][n];
    int mxlen = 0 , st = 0;
    memset(dp , 0 , sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        mxlen = 1;
    }
    for (int i = 0; i < n-1; i++)
    {
        if (s[i] == s[i+1])
        {
            dp[i][i+1] = 1;
            st = i;
            mxlen = 2;
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
                    st = i;
                    mxlen = k;
                }
            }
        }
    }
    return s.substr(st , mxlen);
}

int main(){

}