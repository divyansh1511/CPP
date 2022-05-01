#include<bits/stdc++.h>
using namespace std;

bool ishelper(int sv , vector<int> adj[] , int* color){
    queue<int> q;
    q.push(sv);
    color[sv] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool checkbiparatite(vector<int> adj[] , int n){
    int* color = new int[n];
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!ishelper(i , adj , color))
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
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        int first , second;
        cin>>first>>second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }
    
}