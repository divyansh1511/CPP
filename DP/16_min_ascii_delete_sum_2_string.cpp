#include<bits/stdc++.h>
using namespace std;

int gg(string s , int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (int)s[i];
    }
    return sum;
}

int mindeletesum(string s1 , string s2){
    int n = s1.length();
    int m = s2.length();
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j == 0)
            {
                dp[i][j] = gg(s1 , i);
            }
            else if (i == 0)
            {
                dp[i][j] = gg(s2 , j);
            }
            else if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                int a1 = s1[i-1] + dp[i-1][j];
                int a2 = s2[j-1] + dp[i][j-1];
                dp[i][j] = min(a1 , a2);
            }
        }
    }
    return dp[n][m];
}

int main(){
    cout<<mindeletesum("sea" , "eat")<<endl;
}