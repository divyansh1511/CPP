#include<bits/stdc++.h>
using namespace std;

int palindromesubstring(string s){
    int n = s.length();
    vector<vector<int>> dp(n , vector<int>(n));
    int count = 0;
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 1; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (i+1 == j)
            {
                dp[i][j] = s[i] == s[j] ? 1 : 0;
            }
            else
            {
                dp[i][j] = s[i] == s[j] ? dp[i+1][j-1] : 0;
            }
            count += dp[i][j];
        }
    }
    return count;
}

int main(){

}