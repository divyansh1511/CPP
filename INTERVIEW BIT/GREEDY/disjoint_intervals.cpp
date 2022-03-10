#include<bits/stdc++.h>
using namespace std;

int disjoint(vector<vector<int>> &v){
    sort(v.begin() , v.end());
    vector<vector<int>> ans;
    ans.push_back(v[0]);
    for (int i = 0; i < v.size(); i++)
    {
        if (ans.back()[1] >= v[i][0])
        {
            ans.back()[1] = min(ans.back()[1] , v[i][1]);
        }
        else
        {
            ans.push_back(v[i]);
        }
    }
    return ans.size();
}

int main(){
    
}