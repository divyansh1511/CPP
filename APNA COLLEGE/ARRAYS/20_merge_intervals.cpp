#include<bits/stdc++.h>
using namespace std;

static bool cmp(vector<int> v1 , vector<int> v2){
    if (v1[0] == v2[0])
    {
        return v1[1] < v2[1];
    }
    return v1[0] < v2[0];
}

vector<vector<int>> mergeIntervals(vector<vector<int>> v){
    sort(v.begin() , v.end() , cmp);
    vector<vector<int>> ans;
    ans.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        if(ans[ans.size()-1][1] >= v[i][0]){
            ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1] , v[i][1]);
        }
        else
        {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> v = {{6,8},{1,9},{2,4},{4,7}};
    vector<vector<int>> ans = mergeIntervals(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}