#include<bits/stdc++.h>
using namespace std;

void spiralorder(vector<vector<int>> v){
    int n = v.size() , m = v[0].size();
    int i = 0 , j = 0;
    while (i<n && j<m)
    {
        for (int k = j; k < m; k++)
        {
            cout<<v[i][k]<<" ";
        }
        i++;
        for (int k = i; k < n; k++)
        {
            cout<<v[k][m-1]<<" ";
        }
        m--;
        if (j < m)
        {
            for (int k = m-1; k >= j; k--)
            {
                cout<<v[n-1][k]<<" ";
            }
            n--;
        }
        if (i < n)
        {
            for (int k = n-1; k >= i; k--)
            {
                cout<<v[k][j]<<" ";
            }
            j++;
        }
    }
}

int main(){
    vector<vector<int>> v = {{1,2,3} , {4,5,6} , {7,8,9}};
    spiralorder(v);
}