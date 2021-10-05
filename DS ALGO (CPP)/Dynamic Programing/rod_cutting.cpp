#include<iostream>
using namespace std;

int knapsackdp(int len[] , int pr[] , int T , int n){
    int dp[n+1][T+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= T; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            if (len[i-1] <= j)
            {
                dp[i][j] = max(pr[i-1] + dp[i][j - len[i-1]] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][T];
}

int main(){
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = sizeof(price) / sizeof(price[0]);
    int length[n];
    for (int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    cout<<knapsackdp(length , price , n , n);
}