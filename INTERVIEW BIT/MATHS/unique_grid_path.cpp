#include<bits/stdc++.h>
using namespace std;

//----------------RECURSTION-----------------------//

int uniquePathhelper(int a , int b){
    if (a < 0 || b < 0)
    {
        return 0;
    }
    else if (a == 0 || b == 0)
    {
        return 1;
    }
    else
    {
        return uniquePathhelper(a - 1 , b) + uniquePathhelper(a , b-1);
    }
}

int uniquePath(int a , int b){
    return uniquePathhelper(a-1 , b-1);
}

// -------------------------- DP--------------------//

int uniquepath(int a , int b){
    vector<vector<int>> dp(a , vector<int>(b , 1));
    for (int i = 1; i < a; i++)
    {
        for (int j = 1; j < b; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[a-1][b-1];
}

int main(){
    cout<<uniquePath(3 , 7)<<endl;
    cout<<uniquepath(3 , 7)<<endl;
}