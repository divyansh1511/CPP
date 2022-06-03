#include <bits/stdc++.h>
using namespace std;

//----------------------------RECURSION--------------------//

int helper(int i, int j, int arr[])
{
    if (i == j)
    {
        return 0;
    }
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + helper(i, k, arr) + helper(k + 1, j, arr);
        if (steps < mini)
        {
            mini = steps;
        }
    }
    return mini;
}

int MCM(int arr[], int n)
{
    return helper(1, n - 1, arr);
}

//------------------------memoization-------------------------//

int MCMmemhelper(int i, int j, int arr[], vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + MCMmemhelper(i, k, arr, dp) + MCMmemhelper(k + 1, j, arr, dp);
        if (steps < mini)
        {
            mini = steps;
        }
    }
    return dp[i][j] = mini;
}

int MCMmem(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return MCMmemhelper(1, n - 1, arr, dp);
}

//-------------------------Tabulation-----------------------------//

int MCMtab(int arr[], int n)
{
    int dp[n][n];
    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                if (steps < mini)
                {
                    mini = steps;
                }
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n - 1];
}

//----------------------PALINDROME PARTITION------------------------//

bool ispalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int helper(string s, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if (ispalindrome(s, i, j) == true)
    {
        return 0;
    }
    int mini = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        int temp = 1 + helper(s, i, k) + helper(s, k + 1, j);
        if (temp < mini)
        {
            mini = temp;
        }
    }
    return mini;
}

int palindromepar(string s, int n)
{
    return helper(s, 0, n - 1);
}

//----------------------dp-----------------------//

int palindromicPartition(string str)
{
    // code here
    int cut[str.length()];
    bool pal[str.length()][str.length()];
    memset(pal, false, sizeof(pal));
    for (int i = 0; i < str.length(); i++)
    {
        int minicut = i;
        for (int j = 0; j <= i; j++)
        {
            if (str[i] == str[j] && (i - j < 2 || pal[j + 1][i - 1]))
            {
                pal[j][i] = true;
                minicut = min(minicut, j == 0 ? 0 : (cut[j - 1] + 1));
            }
        }
        cut[i] = minicut;
    }
    return cut[str.length() - 1];
}

int main()
{
}