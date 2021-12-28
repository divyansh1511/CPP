#include<iostream>
using namespace std;

int permutation(int n , int k){
    int dp[n+1][k+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i , k); j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = j*dp[i-1][j-1] + dp[i-1][j];
            }
            dp[i][j+1] = 0;
        }
    }
    return dp[n][k];
}

int main(){
    cout<<permutation(5 , 2)<<endl;
}