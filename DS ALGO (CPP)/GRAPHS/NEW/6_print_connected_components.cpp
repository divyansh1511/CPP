#include<bits/stdc++.h>
using namespace std;

//---------------------adjacency matrix------------------//

void helper(int** edges , int n , int sv , bool* &visited){
    cout<<sv<<endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[i][sv] == 1 && !visited[i])
        {
            helper(edges , n , i , visited);
        }
    }
}

void printconnectedcomponents(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            helper(edges , n , i , visited);
            cout<<endl;
        }
    }
}

//---------------------------adjacency list------------------------//

void helperlist(vector<vector<int>> v , int n , int sv , bool* &visited){
    cout<<sv<<endl;
    visited[sv] = true;
    for(auto it : v[sv]){
        if (!visited[it])
        {
            helperlist(v , n , it , visited);
        }
    }
}

void printconnectlist(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            helperlist(v , n , i , visited);
            cout<<endl;
        }
    }
}

int main(){

}