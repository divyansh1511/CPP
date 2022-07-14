#include<bits/stdc++.h>
using namespace std;

vector<int> printvertexcorner(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if (!visited[j])
                {
                    visited[j] = true;
                    visited[i] = true;
                    break;
                }
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){

}