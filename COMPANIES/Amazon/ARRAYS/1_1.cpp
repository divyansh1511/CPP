#include<bits/stdc++.h>
using namespace std;

void RotateMatrix(vector<vector<int>> &v){
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(v[i][j] , v[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(v[i].begin() , v[i].end());
    }
}

int main(){
    vector<vector<int>> v = {{1,2,3} , {4,5,6} , {7,8,9}};
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    RotateMatrix(v);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}