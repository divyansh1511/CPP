#include<bits/stdc++.h>
using namespace std;

int findcommon(vector<vector<int>> v){
    unordered_map<int , int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i][0]]++;
        for (int j = 1; j < v[i].size(); j++)
        {
            if (v[i][j] != v[i][j-1])
            {
                mp[v[i][j]]++;
            }
        }
    }
    for(auto it : mp){
        if (it.second == v.size())
        {
            return it.first;
        }
    }
    return -1;
}

int main(){

}