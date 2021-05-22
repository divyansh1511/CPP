#include<iostream>
using namespace std;

void printconnectedhelper(int** edges , int n , int sv , bool* visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[i][sv] == 1 && !visited[i])
        {
            printconnectedhelper(edges , n , i , visited);
        }
        
    }
    
}

void printconnected(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printconnectedhelper(edges , n , i , visited);
            cout<<endl;
        }
        
    }
    
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
    printconnected(edges , n);
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