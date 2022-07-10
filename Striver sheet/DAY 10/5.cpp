#include<bits/stdc++.h>
using namespace std;

void DFS(int row , int col , vector<vector<int>> &v , int n , string s , vector<string> &ans){
    if (row < 0 || col < 0 || row > n || col > n || v[row][col] == 0)
    {
        return;
    }
    if (row == n-1 && col == n-1)
    {
        ans.push_back(s);
        return;
    }
    v[row][col] = 0;
    DFS(row+1 , col , v , n , s+'D' , ans);
    DFS(row-1 , col , v , n , s+'U' , ans);
    DFS(row , col+1 , v , n , s+'R' , ans);
    DFS(row , col-1 , v , n , s+'L' , ans);
    v[row][col] = 1;
}

vector<string> findPath(vector<vector<int>> v , int n){
    if (v[0][0] == 0 || v[n-1][n-1] == 0)
    {
        return {"-1"};
    }
    vector<string> ans;
    string s = "";
    DFS(0 , 0 , v , n , s , ans);
    return ans;
}

int main(){

}