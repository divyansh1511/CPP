#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*--------------------------------recursion---------------------------*/

int maxdivide(int a , int b){
    while (a%b == 0)
    {
        a = a/b;
    }
    return a;
}

bool isugly(int no){
    no = maxdivide(no , 2);
    no = maxdivide(no , 3);
    no = maxdivide(no , 5);

    return (no == 1) ? true : false;
}

int uglynum(int n){
    int i = 1;
    int count = 1;
    while (n > count)
    {
        i++;
        if (isugly(i))
        {
            count++; 
        }
    }
    return i;
}

/*-----------------------DP---------------------------------*/

int ughlydp(int n){
    int c2 = 0 , c3 = 0 , c5 = 0;
    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = min({2*dp[c2] , 3*dp[c3] , 5*dp[c5]});
        if (2*dp[c2] == dp[i])
        {
            c2++;
        }
        if (3*dp[c3] == dp[i])
        {
            c3++;
        }
        if (5*dp[c5] == dp[i])
        {
            c5++;
        }
    }
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    cout<<uglynum(n)<<endl;
    cout<<ughlydp(n)<<endl;
}