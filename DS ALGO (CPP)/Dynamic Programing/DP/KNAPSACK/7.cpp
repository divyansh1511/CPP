#include<bits/stdc++.h>
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
    int dp[m+1][n+1];
    memset(dp , 0 , sizeof(dp));
    for(auto &s : strs){
        int a = count(s.begin() , s.end() , '1');
        int b = s.length() - a;
        for(int i=m;i>=b;i--){
            for(int j=n;j>=a;j--){
                dp[i][j] = max(dp[i][j] , dp[i-b][j-a] + 1);
            }
        }
    }
    return dp[m][n];
}

int main(){

}