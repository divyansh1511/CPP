#include<bits/stdc++.h>
using namespace std;

int decodeways(string s){
    int n = s.length();
    int dp[n+1];
    dp[n] = 1;
    for (int i = n-1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            dp[i] = dp[i+1];
        }
        else
        {
            dp[i] = dp[i+1];
            if (i < n-1 && (s[i] == '1' || s[i] == '2' && s[i+1] < '7'))
            {
                dp[i] += dp[i+2];
            }
        }
    }
    return s.empty() ? 0 : dp[0];
}

int main(){

}