#include<bits/stdc++.h>
using namespace std;

vector<int> getpathhelper(int** edges , int n , int sv , int ev , bool* visited){
    if (sv == ev)
    {
        vector<int> output;
        output.push_back(ev);
        return output;
    }
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1 && !visited[i])
        {
            vector<int> output = getpathhelper(edges , n , i , ev , visited);
            if (output.size() != 0)
            {
                output.push_back(sv);
                return output;
            }
        }
    }
    vector<int> a;
    return a;
}

vector<int> getpath(int** edges , int n , int sv , int ev){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    vector<int> output = getpathhelper(edges , n , sv , ev , visited);
    return output;
}

int main(){
    int n,e;
    cin>>n>>e;
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
    vector<int> ans = getpath(edges , n , 1 , 4);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}