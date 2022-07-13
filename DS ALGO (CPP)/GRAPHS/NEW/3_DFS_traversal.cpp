#include<bits/stdc++.h>
using namespace std;

//--------------------adjacency matrix--------------//

void DFShelper(int** edges , int n , int sv , bool* visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (!visited[i])
        {
            DFShelper(edges , n , i , visited);
        }
    }
}

void DFS(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFShelper(edges , n , i , visited);
        }
    }
}

//------------------------adjacency list---------------------//

void DFSlisthelper(vector<vector<int>> v , int n , int sv , bool* visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for(auto it : v[sv]){
        if (!visited[it])
        {
            DFSlisthelper(v , n , sv , visited);
        }
    }
}

void DFSlist(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFSlisthelper(v , n , i , visited);
        }
    }
}

int main(){

}