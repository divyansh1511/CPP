#include<bits/stdc++.h>
using namespace std;

vector<int> pascals(int row){
    vector<vector<int>> v(row+1);
    for (int i = 0; i <= row; i++)
    {
        v[i].resize(i+1);
        v[i][0] = v[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }
    return v[row];
}

int main(){
    vector<int> ans = pascals(4);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}