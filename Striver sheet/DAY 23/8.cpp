#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void findtopsort(vector<int> adj[] , int sv , vector<int> &visited , stack<int> &st){
    visited[sv] = true;
    
    for (auto it : adj[sv])
    {
        if (!visited[it])
        {
            findtopsort(adj , it , visited , st);
        }
    }
    st.push(sv);
}

vector<int> toposort(vector<int> adj[] , int n){
    stack<int> st;
    vector<int> visited(n , 0);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            findtopsort(adj , i , visited , st);
        }
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

int main(){ 
    int n,e;
    cin>>n>>e;
    
    vector<int> adj[n];
    for (int i = 0; i < e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
}