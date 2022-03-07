#include<bits/stdc++.h>
using namespace std;

//---------------------------LONGEST COMMON SUBSEQUENCE----------------------------------//

int lcsDP(string a , string b , int n , int m){
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i-1] == b[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

//------------------LONGEST COMMON SUBSTRING-------------------------//

string lcSdp(string a , string b , int n , int m){
    string dp[n+1][m+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = "";
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i-1] == b[i-1])
            {
                dp[i][j] = a[i-1] + dp[i-1][j-1];
            }
            else
            {
                string t1 = dp[i-1][j];
                string t2 = dp[i][j-1];
                dp[i][j] = t1.length() > t2.length() ? t1 : t2;
            }
        }
    }
    return dp[n][m];
}

//-----------------------LONGEST PALIDROME SUBSTRING-------------------------//

int LPS(string a , int n){
    string b = a;
    reverse(b.begin() , b.end());
    return lcsDP(a , b , n , n);
}

//----------------------MINIMUM NO OF DELETION TO MAKE STRING PALINDROME------------------//

int mindel(string a , int n){
    return n - LPS(a , n);
}

//----------------------LONGEST REPEATING SUBSEQUENCE-----------------------------//

int LRS(string a , int n){
    int dp[n+1][n+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i-1] == a[j-1] && i != j)
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }  
        }
    }
    return dp[n][n];
}

int main(){

}