#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LCSrec(string s1 , string s2 , int n1 , int n2){
    if (n1 == 0 || n2 == 0)
    {
        return 0;
    }
    if (s1[n1-1] == s2[n2-1])
    {
        return 1 + LCSrec(s1 , s2 , n1-1 , n2-1);
    }
    else
    {
        return max(LCSrec(s1 , s2 , n1 -1 , n2) , LCSrec(s1 , s2 , n1 , n2-1));
    }
}

int LCSmem(string s1 , string s2 , int n1 , int n2){
    int dp[n1+1][n2+1];
    memset(dp , -1 , sizeof(dp));
    if (n1 == 0 || n2 == 0)
    {
        return 0;   
    }
    if (dp[n1][n2] != -1)
    {
        return dp[n1][n2];
    }
    if (s1[n1-1] == s2[n2-1])
    {
        return dp[n1][n2] = 1+LCSmem(s1 , s2 , n1-1 , n2-1);
    }
    else
    {
        return dp[n1][n2] = max(LCSmem(s1 , s2 , n1-1 , n2) , LCSmem(s1 ,s2 , n1 , n2-1));
    }
}

int LCSdp(string s1 , string s2 , int n1 , int n2){
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
            if (s1[i-1] == s2[j-1])
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

int main(){
    cout<<LCSrec("hello" , "werld" , 5 ,5)<<endl;
    cout<<LCSmem("hello" , "werld" , 5 ,5)<<endl;
    cout<<LCSdp("hello" , "werld" , 5 ,5)<<endl;
}