#include<bits/stdc++.h>
using namespace std;

vector<int> toposort(unordered_map<int , list<int>> v , int n){
    int* indegree = new int[n];
    for(auto it : v){
        for(auto x : it.second){
            indegree[x]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        ans.push_back(a);
        for(auto it : v[a]){
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return ans;
}

int main(){
    int n,e;
    cin>>n>>e;
    // vector<vector<int>> v;
    unordered_map<int , list<int>> v;
    for (int i = 0; i < e; i++)
    {
        int first , second;
        cin>>first>>second;
        v[first].push_back(second);
    }
    
}