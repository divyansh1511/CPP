#include<bits/stdc++.h>
using namespace std;

bool ishelper(int sv , vector<int> adj[] , int* color){
    if (color[sv] == -1)
    {
        color[sv] = 1;
    }
    for(auto it : adj[sv]){
        if (color[it] == -1)
        {
            color[it] = 1-color[sv];
            if (!ishelper(it , adj , color))
            {
                return false;
            }
        }
        else if (color[it] == color[sv])
        {
            return false;
        }
    }
    return true;
}

bool checkbiparatiteDFS(vector<int> adj[] , int n){
    int* color = new int[n];
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!ishelper(i , adj , color))
            {
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        int first , second;
        cin>>first>>second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }
    
}