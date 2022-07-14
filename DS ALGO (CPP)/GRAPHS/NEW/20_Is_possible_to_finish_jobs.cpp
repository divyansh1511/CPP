#include<bits/stdc++.h>
using namespace std;

bool helper(vector<unordered_set<int>> v , int sv , vector<bool> &visited , vector<bool> &onpath){
    if (visited[sv])
    {
        return false;
    }
    onpath[sv] = visited[sv] = true;
    for(auto it : v[sv]){
        if (onpath[it] || helper(v , it , visited , onpath))
        {
            return true;
        }
    }
    return false;
}

bool isPossible(vector<vector<int>> edges , int n){
    vector<unordered_set<int>> v(n);
    for(auto it : edges){
        v[it[0]].insert(it[1]);
    }
    vector<bool> onpath(n , false);
    vector<bool> visited(n , false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && helper(v , i , visited , onpath))
        {
            return false;
        }
    }
    return true;
}

int main(){

}