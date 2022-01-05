//---------------------ROTATE MATRIX-------------------------//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> v){
    vector<vector<int>> ans;
    for (int i = 0; i < v[0].size(); i++)
    {
        vector<int> temp;
        for (int j = 0; j < v.size(); j++)
        {
            temp.push_back(v[j][i]);
        }
        reverse(temp.begin() , temp.end());
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> ans = rotate(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}