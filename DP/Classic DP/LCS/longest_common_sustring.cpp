#include<bits/stdc++.h>
using namespace std;

string LCSrec(string s1 , string s2 , int n , int m){
    if (n == 0 || m == 0)
    {
        return "";
    }
    if (s1[n-1] == s2[m-1])
    {
        return s1[n-1] + LCSrec(s1 , s2 , n-1 , m-1);
    }
    else
    {
        string a = LCSrec(s1 , s2 , n-1 , m);
        string b = LCSrec(s1 , s2 , n , m-1);
        return a.length() > b.length() ? a : b;
    }
}

string LCSdp(string s1 , string s2 , int n , int m){
    string dp[n+1][m+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = "";
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = s1[i-1]+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = dp[i-1][j].length() > dp[i][j-1].length() ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }
    return dp[n][m];
}

int main(){

}