#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(N*M) SPACE COMPLEXITY : O(M+N)

void setzeros(vector<vector<int>> v){
    map<int , int>c,r;
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; i++)
        {
            if (v[i][j] == 0)
            {
                r[i] = 1;
                c[i] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (r[i] == 1 || c[j] == 1)
            {
                v[i][j] = 0;
            }
        }
    }
}

//OPTIMISATION TIME COMPLEXITY : O(N*M) SPACE COMPLEXITY : O(1)

void setzerosopti(vector<vector<int>> v){
    bool firstrow = false;
    bool firstcol = false;
    int n = v.size() , m = v[0].size();
    for (int i = 0; i < m; i++)
    {
        if (v[0][i] == 0)
        {
            firstrow = true;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i][0] == 0)
        {
            firstcol = true;
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                v[i][0] = 0;
                v[0][i] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
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