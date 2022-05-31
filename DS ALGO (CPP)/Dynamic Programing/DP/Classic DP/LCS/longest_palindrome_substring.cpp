#include<bits/stdc++.h>
using namespace std;

string LPS(string a){
    int n = a.length();
    vector<vector<bool>> dp(n , vector<bool>(n , false));
    int start , len;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0,j = k; j < n; i++, j++)
        {
            if (k == 0)
            {
                dp[i][j] = true;
            }
            else if (k == 1)
            {
                if (a[i] == a[j])
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
                if (a[i] == a[j] && dp[i+1][j-1])
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
    return a.substr(start , len);
}

int main(){

}