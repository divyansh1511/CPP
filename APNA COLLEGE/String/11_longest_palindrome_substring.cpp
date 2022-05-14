#include<bits/stdc++.h>
using namespace std;

string LongestPalindromeSub(string s){
    int n = s.length();
    vector<vector<int>> dp(n , vector<int>(n , false));
    int start , len;
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
                if (s[i] == s[j] && dp[i+1][j-1])
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
                len = j-i+1;
            }
        }
    }
    return s.substr(start , len);
}

int main(){

}