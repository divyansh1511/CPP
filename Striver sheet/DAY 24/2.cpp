#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void getminvertex(int* distance , bool* visited , int n){
    int minvertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minvertex == -1 && distance[i] < distance[minvertex]))
        {
            minvertex = i;
        }
    }
    return minvertex;
}

void dijkstra(int** edges , int n){
    int* distance = new int[n];
    bool* visited = new int[n];

    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int minvertex = getminvertex(distance , visited , n);
        visited[minvertex] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[minvertex][j] != 0 && !visited[j])
            {
                int dis = distance[minvertex] + edges[minvertex][j];
                if (dis < distance[j])
                {
                    distance[j] = dis;
                }
            }
        }
    }
    
}

int main(){

}