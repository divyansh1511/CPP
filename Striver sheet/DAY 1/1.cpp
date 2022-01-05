//--------------------SET MATRIX ZERO------------------//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> setzero(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row;
    vector<int> col;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                row.push_back(i);
                col.push_back(j);
            }
        }
    }
    for (int i = 0; i < row.size(); i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[row[i]][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < col.size(); j++)
        {
            matrix[i][col[j]] = 0;
        }
    }
    return matrix;
}

int main(){
    vector<vector<int>> v = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> ans = setzero(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}