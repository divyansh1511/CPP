#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int> , int>> PrimsAlgo(unordered_map<int , list<pair<int,int>>> mp , int n){
    vector<int> key(n+1 , INT_MAX);
    vector<bool> mst(n+1 , false);
    vector<int> parent(n+1 , -1);

    key[1] = -1;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;
        for (int j = 1; j < n; j++)
        {
            if (mst[j] == false && key[j] < mini)
            {
                u = j;
                mini = key[j];
            }
        }
        mst[u] = true;
        for(auto it : mp[u]){
            int a = it.first;
            int b = it.second;
            if (mst[a] == false && b < key[a])
            {
                parent[a] = u;
                key[a] = b;
            }
        }
    }
    vector<pair<pair<int,int> , int>> ans;
    for (int i = 2; i <= n; i++)
    {
        ans.push_back({{parent[i] , i} , key[i]});
    }
    return ans;
}

int main(){

}