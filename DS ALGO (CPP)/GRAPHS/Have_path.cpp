#include<iostream>
using namespace std;

bool havepath_DFS(int** edges ,int n, int v1 , int v2 , bool* visited){
    visited[v1] = true;

    if (edges[v1][v2] == 1)
    {
        return true;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (i == v1)
        {
            continue;
        }
        if (edges[v1][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            if (havepath_DFS(edges , n , i , v2 , visited))
            {
                return true;
            }   
        }
    }
    return false;
}

bool havepathDFS(int** edges , int n , int v1 ,int v2){
    bool* visited = new bool[n];
    return havepath_DFS(edges , n , v1 , v2 , visited);
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
    cout<<havepathDFS(edges , n , 1,6)<<endl;
}

// 8 8
// 0 4
// 0 5
// 1 2
// 2 3
// 1 3
// 3 6
// 3 4
// 5 6