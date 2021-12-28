#include<iostream>
using namespace std;

int binomialcoff(int n , int k){
    int dp[n+1][k+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++) // ------------ instead of k u can use min(i , k)
        {
            if (j == 0 || j == i)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    return dp[n][k];
}

int main(){
    cout<<binomialcoff(5 , 2)<<endl;
}