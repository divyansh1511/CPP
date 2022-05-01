#include<bits/stdc++.h>
using namespace std;

int getminvertex(int* distances , bool* visited , int n){
    int minvertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minvertex == -1 || distances[minvertex] > distances[i]))
        {
            minvertex = i;
        }
    }
    return minvertex;
}

void dijkstra(int** edges , int n){
    int* distances = new int[n];
    bool* visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        distances[i] = INT_MAX;
        visited[i] = false;
    }
    distances[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int minvertex = getminvertex(distances , visited , n);
        visited[minvertex] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[j][minvertex] != 0 && !visited[j])
            {
                int dis = distances[minvertex] + edges[minvertex][j];
                if (dis < distances[j])
                {
                    distances[j] = dis;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<distances[i]<<" ";
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
        int first , second , weight;
        cin>>first>>second>>weight;
        edges[first][second] = weight;
        edges[second][first] = weight;
    }
    dijkstra(edges , n);
}