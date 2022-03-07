#include<bits/stdc++.h>
using namespace std;

//--------------------------RECURSIVE---------------------------------//

int helper(int i , int j , vector<vector<int>> triangle , int n){
    if (i == n-1)
    {
        return triangle[n-1][j];
    }
    int d1 = triangle[i][j] + helper(i+1 , j , triangle , n);
    int d2 = triangle[i][j] + helper(i+1 , j+1 , triangle , n);
    return min(d1 , d2);
}

int minPath(vector<vector<int>> triangle , int n){
    int i = 0 , j = 0;
    return helper(i , j , triangle , n);
}

//---------------------------Memozise-----------------------//

int helpermem(int i , int j , vector<vector<int>> triangle , int n , vector<vector<int>> &dp){
    if (i == n-1)
    {
        return triangle[n-1][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int d1 = triangle[i][j] + helpermem(i+1 , j , triangle , n , dp);
    int d2 = triangle[i][j] + helpermem(i+1 , j+1 , triangle , n , dp);
    return dp[i][j] = min(d1 , d2);
}

int minPathmem(vector<vector<int>> triangle , int n){
    vector<vector<int>> dp(n , vector<int>(n , -1));
    return helpermem(0 , 0 , triangle , n , dp);
}

//---------------------------Tabulation----------------------------//

int minPathdp(vector<vector<int>> triangle , int n){
    vector<vector<int>> dp(n , vector<int>(n , 0));
    for (int i = 0; i < n; i++)
    {
        dp[n-1][i] = triangle[n-1][i];
    }
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int d1 = triangle[i][j] + dp[i+1][j];
            int d2 = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(d1 , d2);
        }
    }
    return dp[0][0];
}

//-------------------------Space optimise--------------------------//

int minPathdpopti(vector<vector<int>> triangle , int n){
    vector<int> front(n , 0) , curr(n , 0);
    for (int i = 0; i < n; i++)
    {
        front[i] = triangle[n-1][i];
    }
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int d1 = triangle[i][j] + front[j];
            int d2 = triangle[i][j] + front[j+1];
            curr[j] = min(d1 , d2);
        }
        front = curr;
    }
    return front[0];
}

int main(){
    vector<vector<int>> tri = {{1} , {2,3} , {4,5,6} , {7,8,9,10}};
    cout<<minPath(tri , 4)<<endl;
    cout<<minPathmem(tri , 4)<<endl;
    cout<<minPathdp(tri , 4)<<endl;
    cout<<minPathdpopti(tri , 4)<<endl;
}