#include<bits/stdc++.h>
using namespace std;

int rottingoranges(vector<vector<int>> &grid){
    int n = grid.size() , m = grid[0].size();
    int tot = 0 , cnt = 0 , days = 0;
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0)
            {
                tot++;
            }
            if (grid[i][j] == 2)
            {
                q.push({i,j});
            }
        }
    }
    int dx[] = {0 , 0 , 1 , -1};
    int dy[] = {1 , -1 , 0 , 0};
    while (!q.empty())
    {
        int k = q.size();
        cnt += k;
        while (k--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x+dx[i] , ny = y+dy[i];
                if (nx < 0 || nx > n-1 || ny < 0 || ny > m-1 || grid[nx][ny] != 1)
                {
                    continue;
                }
                grid[nx][ny] = 2;
                q.push({nx , ny});
            }
        }
        if (!q.empty())
        {
            days++;
        }
    }
    return tot == cnt ? days : -1;
}

int main(){

}