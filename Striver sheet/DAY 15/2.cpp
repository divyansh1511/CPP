#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string longestpalindrome(string s){
    int n = s.length();
    int start , end;
    vector<vector<bool>> dp(n , vector<bool>(n , false));
    for (int k = 0; k < n; k++)
    {
        for (int i = 0 , j = k; j < n; i++ , j++)
        {
            if (k == 0)
            {
                dp[i][j] = true;
            }
            else if (k == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            else
            {
                if (s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            if (dp[i][j])
            {
                start = i;
                end = j - i + 1;
            }
        }
    }
    return s.substr(start , end);
}

int main(){
    cout<<longestpalindrome("babad")<<endl;
}