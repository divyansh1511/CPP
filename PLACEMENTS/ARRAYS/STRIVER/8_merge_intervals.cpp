#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &v){
    if (v.size() <= 1)
    {
        return v;
    }
    sort(v.begin() , v.end());
    vector<vector<int>> ans;
    ans.push_back(v[0]);
    int j = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (ans[j][1] > v[i][0])
        {
            ans[j][i] = max(ans[j][1] , v[i][1]);
        }
        else
        {
            j++;
            ans.push_back(v[i]);
        }
    }
    return ans;
}

int main(){

}