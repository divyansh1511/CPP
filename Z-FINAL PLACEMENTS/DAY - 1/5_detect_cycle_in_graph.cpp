#include<bits/stdc++.h>
using namespace std;

bool iscyclehelper(vector<vector<int>> v , int sv , bool* &dfsvisited , bool* &visited){
    visited[sv] = true;
    dfsvisited[sv] = true;
    for(auto it : v[sv]){
        if (!visited[it])
        {
            if (iscyclehelper(v , it , dfsvisited , visited))
            {
                return true;
            }
        }
        else if (dfsvisited[it])
        {
            return true;
        }
    }
    dfsvisited[sv] = false;
    return false;
}

bool iscycle(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    bool* dfsvisited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (iscyclehelper(v , i , dfsvisited , visited))
            {
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> v(n);
    for (int i = 0; i < e; i++)
    {
        int first , second;
        cin>>first>>second;
        v[first].push_back(second);
    }
    
}