#include<bits/stdc++.h>
using namespace std;

//---------------------using adjacency matrix-----------------------//

void BFShelper(int** edges , int n , int sv , bool* &visited){
    queue<int> pendingvertex;
    pendingvertex.push(sv);
    visited[sv] = true;
    while (!pendingvertex.empty())
    {
        int currindex = pendingvertex.front();
        pendingvertex.pop();
        cout<<currindex<<endl;
        for (int i = 0; i < n; i++)
        {
            if (i == sv)
            {
                continue;
            }
            if (edges[i][sv] == 1 && !visited[i])
            {
                pendingvertex.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFShelper(edges , n , i , visited);
        }
    }
}

//----------------------------using adjacency list---------------------//

void BFSlisthelper(vector<vector<int>> v , int n , int sv , bool* &visited){
    queue<int> pendingvertex;
    pendingvertex.push(sv);
    visited[sv] = true;
    while (!pendingvertex.empty())
    {
        int currindex = pendingvertex.front();
        pendingvertex.pop();
        cout<<currindex<<" ";
        for(auto it : v[currindex]){
            if (!visited[it])
            {
                visited[it] = true;
                pendingvertex.push(it);
            }
        }
    }
}

void BFSlist(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFSlisthelper(v , n , i , visited);
        }
    }
}

int main(){

}