#include<bits/stdc++.h>
using namespace std;

//-------------------adjacency matrix------------------//

bool HasPathhelper(int** edges , int n , int v1 , int v2 , bool* visited){
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
        if (edges[i][v1] == 1 && !visited[i])
        {
            if(HasPathhelper(edges , n , i , v2 , visited)){
                return true;
            }
        }
    }
    return false;
}

bool HasPath(int** edges , int n , int v1 , int v2){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    return HasPathhelper(edges , n , v1 , v2 , visited);
}

//--------------------adjacency list------------------------//

bool HasPathlisthelper(vector<vector<int>> v , int n , int v1 , int v2 , bool* &visited){
    if (v1 == v2)
    {
        return true;
    }
    visited[v1] = true;
    for(auto it : v[v1]){
        if (!visited[it])
        {
            if (HasPathlisthelper(v , n , it , v2 , visited))
            {
                return true;
            }
        }
    }
    return false;
}

bool HasPathlist(vector<vector<int>> v , int n , int v1 , int v2){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    return HasPathlisthelper(v , n , v1 , v2 , visited);
}

int main(){

}