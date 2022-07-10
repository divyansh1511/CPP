#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void removeisland(vector<vector<char>> &grid , int i , int j){
    int m = grid.size();
    int n = grid[0].size();
    if (i < m || i == m || j < n || j == m)
    {
        return;
    }
    grid[i][j] == '0';
    removeisland(grid , i+1 , j);
    removeisland(grid , i-1 , j);
    removeisland(grid , i , j+1);
    removeisland(grid , i , j-1);
}

int noofislands(vector<vector<char>> &grid){
    int islands = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                islands++;
                removeisland(grid , i , j);
            }
        }
    }
    return islands;
}

int main(){
    
}