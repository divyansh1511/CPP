#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> groupThePeople(vector<int>& gr) {
    vector<vector<int>> v;
    unordered_map<int , vector<int>> mp;
    for (int i = 0; i < gr.size(); i++)
    {
        mp[gr[i]].push_back(i);
    }
    for (auto it : mp)
    {
        int k = it.first;
        int in = 0;
        while (in != mp[k].size())
        {
            vector<int> temp;
            for (int i = in; i < in+k; i++)
            {
                temp.push_back(mp[k][i]);
            }
            in += k;
            v.push_back(temp);
        }
    }
    return v;
}

int main(){
    vector<int> gr = {3,3,3,3,3,1,3};
    vector<vector<int>> a = groupThePeople(gr);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}