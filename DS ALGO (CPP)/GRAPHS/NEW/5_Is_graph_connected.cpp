#include<bits/stdc++.h>
using namespace std;

//---------------------adjacency matrix-------------------------//

void isconnectedhelper(int** edges , int n , int sv , bool* visited){
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[i][sv] == 1 && !visited[i])
        {
            isconnectedhelper(edges , n , i , visited);
        }
    }
}

bool isGraphconnected(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    
    isconnectedhelper(edges , n , 0 , visited);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

//--------------------adjacency list------------------//

void isgraphconnectedhelper(vector<vector<int>> v , int n , int sv , bool* &visited){
    visited[sv] = true;
    for(auto it : v[sv]){
        if (!visited[it])
        {
            isgraphconnectedhelper(v , n , it , visited);
        }
    }
}

bool isgraphconnected(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    
    isgraphconnectedhelper(v , n , 0 , visited);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main(){

}