#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printBFS(int** edges , int n , int sv , bool* visited){
    queue<int> pendingnodes;
    pendingnodes.push(sv);
    visited[sv] = true;
    while (!pendingnodes.empty())
    {
        int currvertex = pendingnodes.front();
        pendingnodes.pop();
        cout<<currvertex<<" ";
        for (int i = 0; i < n; i++)
        {
            if (i == currvertex)
            {
                continue;
            }
            if (edges[i][currvertex] == 1 && !visited[i])
            {
                pendingnodes.push(i);
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
        int first,second,weight;
        cin>>first>>second>>weight;
        edges[first][second] = weight;
        edges[second][first] = weight;
    }
    
}