#include<bits/stdc++.h>
using namespace std;

void printans(vector<vector<int>> &ans , int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<ans[i][j]<<" ";
        }
    }
    cout<<endl;
}

void helper(vector<vector<int>> &v , vector<vector<int>> &ans , int n  , int x , int y){
    if (x == n-1 && y == n-1)
    {
        ans[x][y] = 1;
        printans(ans , n);
        ans[x][y] = 0;
        return;
    }
    if (x >= n || x<0 || y < 0 || y>=n || v[x][y] == 0 || ans[x][y] == 1)
    {
        return;
    }
    ans[x][y] = 1;
    helper(v , ans , n , x+1 , y);
    helper(v , ans , n , x-1 , y);
    helper(v , ans , n , x , y+1);
    helper(v , ans , n , x , y-1);
    ans[x][y] = 0;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n , vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>v[i][j];
        }
    }
    vector<vector<int>> ans(n , vector<int>(n , 0));
    helper(v , ans , n , 0 , 0);
}