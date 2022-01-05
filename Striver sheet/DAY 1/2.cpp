//----------------PASCALS TRIANGLE----------------//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalstri(int n){
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].resize(i+1);
        v[i][0] = v[i][i] = 1;
        for (int j = 1; j < v[i].size() - 1; j++)
        {
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }
    return v;
}

int main(){
    vector<vector<int>> ans = pascalstri(5);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}