#include<bits/stdc++.h>
using namespace std;

int rottenoranges(vector<vector<int>> v){
    int n = v.size() , m = v[0].size();
    int total = 0 , cnt = 0 , days = 0;
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] != 0)
            {
                total++;
            }
            if (v[i][j] == 2)
            {
                q.push({i , j});
            }
        }
    }
    int dx[] = {0 , 0 , -1 , 1};
    int dy[] = {1 , -1 , 0 , 0};
    while (!q.empty())
    {
        int k = q.size();
        cnt += k;
        while (k--)
        {
            int x = q.front().first , y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x+dx[i] , ny = y+dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny] != 1)
                {
                    continue;
                }
                v[nx][ny] = 2;
                q.push({nx , ny});
            }
        }
        if (!q.empty())
        {
            days++;
        }
    }
    return total == cnt ? days : -1;
}

int main(){

}