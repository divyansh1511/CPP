#include<bits/stdc++.h>
using namespace std;

//---------------------------------using BFS--------------------------------//

bool isBipratite(vector<vector<int>> v , int n){
    vector<int> color(n , -1);
    queue<int> q;
    color[0] = 1;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto it : v[u]){
            if (color[it] == -1)
            {
                color[it] = 1 - color[u];
                q.push(it);
            }
            else if (color[it] == color[u])
            {
                return false;
            }
        }
    }
    return true;
}

//--------------------------------using DFS------------------------------//

bool helper(vector<vector<int>> v , int sv , vector<int> &color){
    for(auto it : v[sv]){
        if (color[it] == -1)
        {
            color[it] = 1 - color[sv];
            if (!helper(v , it , color))
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

bool checkBiapratite(vector<vector<int>> v , int n){
    vector<int> color(n , -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            if (!helper(v , i , color))
            {
                return false;
            }
        }
    }
    return true;
}

int main(){

}