#include<bits/stdc++.h>
using namespace std;

bool iscyclehelper(vector<int> edges[] , int n , int sv , bool* visited){
    queue<pair<int,int>> q;
    q.push({sv , -1});
    visited[sv] = true;
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto it : edges[node]){
            if (!visited[it])
            {
                q.push({it , node});
                visited[it] = true;
            }
            else if (par != it)
            {
                return true;
            }
        }
    }
    return false;
}

bool iscycle(vector<int> edges[] , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (iscyclehelper(edges , n , i , visited))
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
    vector<int> edges[n];
    for (int i = 0; i < e; i++)
    {
        int first , second;
        cin>>first>>second;
        edges[first].push_back(second);
        edges[second].push_back(first);
    }
    
}