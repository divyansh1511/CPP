#include<bits/stdc++.h>
using namespace std;

void toposort(vector<vector<int>> v , int sv , stack<int> &s , bool* &visited){
    visited[sv] = true;
    for(auto it : v[sv]){
        if (!visited[it])
        {
            toposort(v , it , s , visited);
        }
    }
    s.push(sv);
}

vector<int> topologicalsort(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            toposort(v , i , s , visited);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main(){

}