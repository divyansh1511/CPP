#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotatematrix(vector<vector<int>> v){
    vector<vector<int>> ans;
    for (int j = 0; j < v[0].size(); j++)
    {
        vector<int> a;
        for (int i = 0; i < v.size(); i++)
        {
            a.push_back(v[i][j]);
        }
        reverse(a.begin() , a.end());
        ans.push_back(a);
    }
    return ans;
}

int main(){

}