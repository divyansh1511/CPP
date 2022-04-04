#include<bits/stdc++.h>
using namespace std;

string LCSdp(string a , string b , int n , int m){
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
            if (a[i-1] == b[j-1])
            {
                dp[i][j] = a[i-1] + dp[i-1][j-1];
            }
            else
            {
                string option1 = dp[i-1][j];
                string option2 = dp[i][j-1];
                dp[i][j] = option1.length() > option2.length() ? option1 : option2;
            }
        }
    }
    return dp[n][m];
}

string shortestcommonsuper(string a , string b){
    int i = 0 , j = 0;
    string res = "";
    int n = a.length() , m = b.length();
    string v = LCSdp(a , b , n , m);
    for (char it : v)
    {
        while (a[i] != it)
        {
            res += a[i++];
        }
        while (b[j] != it)
        {
            res += b[j++];
        }
        res += it;
        i++;
        j++;
    }
    return res + a.substr(i) + b.substr(j);
}

int main(){

}