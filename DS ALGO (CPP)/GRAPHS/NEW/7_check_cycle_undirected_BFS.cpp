#include<bits/stdc++.h>
using namespace std;

bool helper(int** edges , int n , int sv , bool* &visited){
    queue<pair<int,int>> q;
    q.push({sv , -1});
    visited[sv] = true;
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        for (int i = 0; i < n; i++)
        {
            if (edges[i][node] == 1)
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push({i , node});
                }
                if (i != par)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool checkCycle(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (helper(edges , n , i , visited))
            {
                return true;
            }
        }
    }
    return false;
}

bool helperlist(vector<vector<int>> v , int n , int sv , bool* visited){
    queue<pair<int,int>> q;
    q.push({sv , -1});
    visited[sv] = true;
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto it : v[node]){
            if (!visited[it])
            {
                visited[it] = true;
                q.push({it , node});
            }
            else if (it != par)
            {
                return true;
            }
        }
    }
    return false;
}

bool checkcyclelist(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (helperlist(v , n , i , visited))
            {
                return true;
            }
        }
    }
    return false;
}

int main(){

}