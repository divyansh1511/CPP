#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int knapsacrec(int wt[] , int val[] , int W , int n){
    if(n == 0 || W == 0){
        return 0;
    }
    if (wt[n-1] <= W)
    {
        return max(val[n-1] + knapsacrec(wt , val , W-wt[n-1] , n-1) , knapsacrec(wt , val , W , n-1));
    }
    else if (wt[n-1] > W)
    {
        return knapsacrec(wt , val , W , n-1);
    }
}

int knapsacmem(int wt[] , int val[] , int W , int n){
    static int t[1002][1002];
    memset(t , -1 , sizeof(t));
    if(n == 0 || W == 0){
        return 0;
    }
    if (t[n][W] != -1)
    {
        return t[n][W];
    }
    if (wt[n-1] <= W)
    {
        return t[n][W] = max(val[n-1] + knapsacmem(wt , val , W-wt[n-1] , n-1) , knapsacmem(wt , val , W , n-1));
    }
    else if (wt[n-1] > W)
    {
        return knapsacmem(wt , val ,W , n-1);
    }
}

int knapsactab(int wt[] , int val[] , int W , int n){
    int dp[n+1][W+1];
    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] +
                                dp[i - 1][w - wt[i - 1]],
                                dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main(){
    int wt[] = {10,20,30};
    int val[] = {60,100,120};
    int W = 50;
    cout<<knapsacrec(wt , val , W , 3)<<endl;
    cout<<knapsacmem(wt , val , W , 3)<<endl;
    cout<<knapsactab(wt , val , W , 3)<<endl;
}