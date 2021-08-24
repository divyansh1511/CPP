#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs(char* a1 , char* a2 , int n , int m){
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (a1[n-1] == a2[m-1])
    {
        return 1+lcs(a1 , a2 , n-1 , m-1);
    }
    else
    {
        return max(lcs(a1 , a2 , n-1 , m) , lcs(a1 , a2 , n , m-1));
    }
}

int lcsDP(char* a1 , char* a2 , int n , int m){
    int LCS[n+1][m+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                LCS[i][j] = 0;
            }
            else if (a1[i-1] == a2[j-1])
            {
                LCS[i][j] = LCS[i-1][j-1]+1;
            }
            else
            {
                LCS[i][j] = max(LCS[i-1][j] , LCS[i][j-1]);
            }
        }
    }
    return LCS[n][m];
}

int main(){
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    cout<<lcs(X , Y , 6 , 7)<<endl;
    cout<<lcsDP(X , Y , 6 , 7)<<endl;
}