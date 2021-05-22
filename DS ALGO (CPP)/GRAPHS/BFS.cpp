#include<iostream>
#include<queue>
using namespace std;

void printBFS(int** edges , int n , int sv , bool* visited){
    queue<int> pendingvertex;
    pendingvertex.push(sv);
    visited[sv] = true;
    
    while (!pendingvertex.empty())
    {
        int currentindex = pendingvertex.front();
        pendingvertex.pop();
        cout<<currentindex<<endl;
        for (int i = 0; i < n; i++)
        {
            if (i == currentindex)
            {
                continue;
            }
            
            if (edges[currentindex][i] == 1 && !visited[i])
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
            printBFS(edges , n , i , visited);
        }
    }
    delete [] visited;
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
        int first,second;
        cin>>first>>second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }

    BFS(edges , n);
}