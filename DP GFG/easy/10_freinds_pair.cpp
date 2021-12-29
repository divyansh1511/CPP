#include<iostream>
using namespace std;

int count(int n){
    int dp[n+1];
    for (int i = 0; i <= n; i++)
    {
        if (i <= 2)
        {
            dp[i] = i;
        }
        else
        {
            dp[i] = dp[i-1] + (i-1)*dp[i-2];
        }
    }
    return dp[n];
}

int main(){
    cout<<count(4)<<endl;
}