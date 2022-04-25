#include<bits/stdc++.h>
using namespace std;

int getarea(vector<vector<int>> &grid , int i , int j){
    if (i >= 0 && i < grid.size() && j >= 0 && grid[0].size())
    {
        grid[i][j] = 0;
        return 1+getarea(grid , i+1 , j) + getarea(grid , i-1 , j) + getarea(grid , i , j+1) + getarea(grid , i , j-1);
    }
    return 0;
}

int maxareaislands(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    int maxarea = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maxarea = max(maxarea , getarea(grid , i , j));
        }
    }
    return maxarea;
}

int main(){

}