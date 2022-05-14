#include<bits/stdc++.h>
using namespace std;

void removeislands(vector<vector<string>> v , int i , int j){
    int n = v.size() , m = v[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m || v[i][j] == "0")
    {
        return;
    }
    v[i][j] = "0";
    removeislands(v , i+1 , j);
    removeislands(v , i-1 , j);
    removeislands(v , i , j+1);
    removeislands(v , i , j-1);
}

int noofislands(vector<vector<string>> v){
    int n = v.size() , m = v[0].size();
    int island = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == "1")
            {
                island++;
                removeislands(v , i , j);
            }
        }
    }
    return island;
}

int main(){

}