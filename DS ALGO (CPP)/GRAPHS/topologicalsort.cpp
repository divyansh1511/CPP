#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    int count = 0;
    vector<vector<int>> adj(n);
    vector<int> indeg(n,0);
    for (int i = 0; i < e; i++)
    {
        int first,second;
        cin>>first>>second;
        adj[first].push_back(second);
        indeg[second]++;
    }
    
    queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            pq.push(i);
        }
    }
    
    while (!pq.empty())
    {
        count++;
        int x = pq.front();
        pq.pop();
        cout<<x<<" ";
        for (auto it : adj[x])
        {
            indeg[it]--;
            if (indeg[it] == 0)
            {
                pq.push(it);
            }
        }
    }
}