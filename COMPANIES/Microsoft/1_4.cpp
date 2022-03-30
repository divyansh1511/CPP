#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> spiralorder(int n){
    int m = n;
    int i = 0 , j = 0;
    int c = 1;
    vector<vector<int>> v;
    while (i<n && j<m)
    {
        for (int k = j; k < m; k++)
        {
            v[i][k] = c;
            c++;
        }
        i++;
        for (int k = i; k < n; k++)
        {
            v[k][m-1] = c;
            c++;
        }
        m--;
        if (j < m)
        {
            for (int k = m-1; k >= j; k--)
            {
                v[n-1][k] = c;
                c++;
            }
            n--;
        }
        if (i < n)
        {
            for (int k = n-1; k >= i; k--)
            {
                v[k][j] = c;
                c++;
            }
            j++;
        }
    }
    return v;
}

int main(){
    int n = 3;
    vector<vector<int>> v =  spiralorder(n);
}