#include<bits/stdc++.h>
using namespace std;

bool DFShelper(int** edges , int n , int sv , int parent , bool* visited){
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[i][sv] == 1)
        {
            if (!visited[i])
            {
                if (DFShelper(edges , n , i , sv , visited))
                {
                    return true;
                }
            }
            else if (i != parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool checkcycleDFS(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (DFShelper(edges , n , i , -1 , visited))
            {
                return true;
            }
        }
    }
    return false;
}

bool DFShelperlist(vector<vector<int>> v , int n , int sv , int parent , bool* visited){
    visited[sv] = true;
    for(auto it : v[sv]){
        if (!visited[it])
        {
            if (DFShelperlist(v , n , it , sv , visited))
            {
                return true;
            }
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}

bool checkcycleDFSlist(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (DFShelperlist(v , n , i , -1 , visited))
            {
                return true;
            }
        }
    }
    return false;
}

int main(){

}