#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,list<int>> mp , stack<int> &s , int sv , unordered_map<int,bool> &vis){
    vis[sv] = true;
    for(auto it : mp[sv]){
        if (!vis[it])
        {
            dfs(mp , s , it , vis);
        }
    }
    s.push(sv);
}

void revdfs(int sv , unordered_map<int,bool> &vis , unordered_map<int , list<int>> &mp){
    vis[sv] = true;
    for(auto it : mp[sv]){
        if (!vis[it])
        {
            revdfs(it , vis , mp);
        }
    }
}

int kosarajusalgo(unordered_map<int,list<int>> mp , int n){
    //topo sort
    stack<int> s;
    unordered_map<int , bool> vis;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(mp , s , i , vis);
        }
    }
    //transpose
    unordered_map<int , list<int>> transpose;
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for(auto it : mp[i]){
            transpose[it].push_back(i);
        }
    }
    //reverse dfs
    int count = 0;
    while (!s.empty())
    {
        int t = s.top();
        s.pop();
        if (!vis[t])
        {
            count++;
            revdfs(t , vis , transpose);
        }
    }
    return count;
}

int main(){
    int n,e;
    cin>>n>>e;
    unordered_map<int , list<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int f,s;
        cin>>f>>s;
        mp[f].push_back(s);
    }
    
}