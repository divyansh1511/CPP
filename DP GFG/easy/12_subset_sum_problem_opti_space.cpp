#include<iostream>
using namespace std;

bool subsetsum(int arr[] , int n , int m){
    int dp[2][m+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j == 0)
            {
                dp[i%2][j] = true;
            }
            else if (i == 0)
            {
                dp[i%2][j] = false;
            }
            else if (arr[i-1] <= j)
            {
                dp[i%2][j] = dp[(i+1)%2][j-arr[i-1]] || dp[(i+1)%2][j];
            }
            else
            {
                dp[i%2][j] = dp[(i+1)%2][j];
            }
        }
    }
    return dp[n%2][m];
}

int main(){
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (subsetsum(set, n, sum) == true)
         cout <<"Found a subset with given sum";
    else
        cout <<"No subset with given sum";
    return 0;
}