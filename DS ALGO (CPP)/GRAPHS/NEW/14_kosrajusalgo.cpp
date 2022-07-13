#include<bits/stdc++.h>
using namespace std;

void toposort(unordered_map<int,list<int>> mp , vector<bool> &visited , int sv , stack<int> &s){
    visited[sv] = true;
    for(auto it : mp[sv]){
        if (!visited[it])
        {
            toposort(mp , visited , it , s);
        }
    }
    s.push(sv);
}

void revdfs(int sv , vector<bool> &vis , unordered_map<int,list<int>> tt){
    vis[sv] = true;
    for(auto it : tt[sv]){
        if (!vis[it])
        {
            revdfs(it , vis , tt);
        }
    }
}

int kosrajusalgo(unordered_map<int,list<int>> mp , int n){
    stack<int> s;
    vector<bool> vis;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            toposort(mp , vis , i , s);
        }
    }
    unordered_map<int , list<int>> tt;
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for(auto it : mp[i]){
            tt[it].push_back(i);
        }
    }
    int count = 0;
    while (!s.empty())
    {
        int t = s.top();
        s.pop();
        if (!vis[t])
        {
            count++;
            revdfs(t , vis , tt);
        }
    }
    return count;
}

int main(){

}