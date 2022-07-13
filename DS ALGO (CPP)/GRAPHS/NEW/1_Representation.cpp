#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    //-------------------using adjacency matrix------------------//
    int** edges = new int*[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int first , second;
        cin>>first>>second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
    //---------------------using adjacency list----------------------//

    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int first , second;
        cin>>first>>second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }
    
    //---------------------weighted graph---------------------------//

    unordered_map<int , list<pair<int,int>>> mp;
    for (int i = 0; i < e; i++)
    {
        int first , second , weight;
        cin>>first>>second>>weight;
        mp[first].push_back({second , weight});
        mp[second].push_back({first , weight});
    }
    
}