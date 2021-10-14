#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> intervals){
    vector<vector<int>> v;
    if (intervals.size() == 0)
    {
        return v;
    }
    sort(intervals.begin() , intervals.end());
    vector<int> temp = intervals[0];
    for (int i = 0; i < intervals.size(); i++)
    {
        if (temp[1] >= intervals[i][0])
        {
            temp[1] = max(temp[1] , intervals[i][1]);
        }
        else
        {
            v.push_back(temp);
            temp = intervals[i];
        }
    }
    v.push_back(temp);
    return v;
}

int main(){
    vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}