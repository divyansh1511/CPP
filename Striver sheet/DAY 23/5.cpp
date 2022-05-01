#include<bits/stdc++.h>
using namespace std;

bool iscycleDFShelper(vector<int> adj[] , int parent , int sv , bool* visited){
    visited[sv] = true;
    for(auto it : adj[sv]){
        if (!visited[it])
        {
            if (iscycleDFShelper(adj , sv , it , visited))
            {
                return true;
            }
            else if (it != parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool iscycleDFS(vector<int> adj[] , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if(iscycleDFShelper(adj , -1 , i , visited)){
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