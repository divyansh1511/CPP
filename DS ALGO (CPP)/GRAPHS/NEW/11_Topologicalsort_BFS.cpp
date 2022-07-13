#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalsort(unordered_map<int, list<int>> mp , int n){
    int* indegree = new int[n];
    for(auto it : mp){
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
        for(auto it : mp[a]){
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

}