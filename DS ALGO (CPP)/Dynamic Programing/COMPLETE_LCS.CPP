#include<bits/stdc++.h>
using namespace std;

//-------------------------------LONGEST COMMON SUBSEQUENCE -------------------------------//

int lcsrec(string a , string b , int n , int m){
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (a[n-1] == b[m-1])
    {
        return 1+lcsrec(a , b , n-1 , m-1);
    }
    else
    {
        return max(lcsrec(a , b , n-1 , m) , lcsrec(a , b , n , m-1));
    }
}

int lcsmem(string a , string b , int n , int m){
    static int dp[1002][1002];
    memset(dp , -1 , sizeof(dp));
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (a[n-1] == b[m-1])
    {
        return dp[n][m] = 1+lcsmem(a , b , n-1 , m-1);
    }
    else
    {
        return dp[n][m] = max(lcsmem(a , b , n-1 , m) , lcsmem(a , b , n , m-1));
    }
}

int lcsdp(string a , string b , int n1 , int n2){
    int dp[n1+1][n2+2];
    memset(dp , -1 , sizeof(dp));
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
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
    return dp[n1][n2];
}

//----------------------------------LONGEST COMMON SUBSTRING ----------------------------//

string LCSrec(string a , string b , int n , int m){
    if (n == 0 || m == 0)
    {
        return "";
    }
    if (a[n-1] == b[m-1])
    {
        return a[n-1] + LCSrec(a , b , n-1 , m-1);
    }
    else
    {
        string option1 = LCSrec(a , b , n-1 , m);
        string option2 = LCSrec(a , b , n , m-1);
        return option1.length() > option2.length() ? option1 : option2;
    }
}

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

//--------------------------- LONGEST PALINDROME SEQUENCE ----------------//

int LPS(string a , int n){
    string b = a;
    reverse(b.begin() , b.end());
    return lcsdp(a , b  , n , n);
}

//----------------------  MINIMUM NO OF DELETION TO MAKE STRING PALINDROME -----------------------//

int minidel(string a , int n){
    return n - LPS(a , n);
}

int main(){
    // cout<<lcsrec("hello" , "werld" , 5 ,5)<<endl;
    // cout<<lcsmem("hello" , "werld" , 5 , 5)<<endl;
    // cout<<lcsdp("hello" , "werld" , 5 , 5)<<endl;
    // string a = LCSrec("abcdefghi","bghicfhi" , 9 , 8);
    // reverse(a.begin() , a.end());
    // cout<<a<<endl;
    // string b = LCSdp("abcdefghi","bghicfhi" , 9 , 8);
    // cout<<b<<endl;
    cout<<LPS("agbcba" , 6)<<endl;
    cout<<minidel("agbcba" , 6)<<endl;
}