#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> diagnoaltraversal(vector<vector<int>> v){
    int n = v.size() , m = v[0].size();
    vector<vector<int>> ans(n+m-1);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i+j].push_back(v[j][i]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> a = {{1,2,3,4} , {5,6,7,8} , {9,10,11,12} , {13,14,15,16}};
    vector<vector<int>> v = diagnoaltraversal(a);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}