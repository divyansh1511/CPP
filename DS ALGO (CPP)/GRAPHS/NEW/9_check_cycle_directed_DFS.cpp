#include<bits/stdc++.h>
using namespace std;

bool checkcyclehelper(vector<vector<int>> v , int sv , bool* visited , bool* dfsvisited){
    visited[sv] = true;
    dfsvisited[sv] = true;
    for(auto it : v[sv]){
        if (!visited[it])
        {
            if (checkcyclehelper(v , it , visited , dfsvisited))
            {
                return true;
            }
        }
        else if (dfsvisited[it])
        {
            return true;
        }
    }
    dfsvisited[sv] = false;
    return false;
}

bool checkcycle(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    bool* dfsvisited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        dfsvisited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (checkcyclehelper(v , i , visited , dfsvisited))
            {
                return true;
            }
        }
    }
    return false;
}

int main(){

}