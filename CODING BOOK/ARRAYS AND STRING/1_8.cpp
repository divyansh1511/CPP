#include<bits/stdc++.h>
using namespace std;

void setzeros(vector<vector<int>> v){
    int n = v.size();
    int m = v[0].size();
    bool firstrow = false;
    bool firstcol = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                if (i == 0)
                {
                    firstrow = true;
                }
                if (j == 0)
                {
                    firstcol = true;
                }
                v[i][0] = 0;
                v[0][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][0] == 0 || v[0][j] == 0)
            {
                v[i][j] = 0;
            }
        }
    }
    if (firstrow)
    {
        for (int i = 0; i < m; i++)
        {
            v[0][i] = 0;
        }
    }
    if (firstcol)
    {
        for (int i = 0; i < n; i++)
        {
            v[i][0] = 0;
        }
    }
}

int main(){

}