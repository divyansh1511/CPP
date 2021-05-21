#include<iostream>
using namespace std;

void isconnectedhelper(int** edges , int n ,int sv , bool* visited){
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
                isconnectedhelper(edges,n,i,visited);
            }
        }
    }
}

bool isconnected(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    
    isconnectedhelper(edges , n , 0 , visited);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }
    return true;
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
    cout<<isconnected(edges , n)<<endl;
}