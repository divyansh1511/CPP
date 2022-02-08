#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> spiralorder(int A){
    vector<vector<int>> v(A , vector<int>(A));
    int i, l = 0 , k = 0;
    int c = 1;
    int m = A, n = A;
    while (l < m && k < n)
    {
        for (i = 0; i < n; i++)
        {
            v[k][i] = c;
            c++;
        }
        k++;
        for (i = k; i < m; i++)
        {
            v[i][n-1] = c;
            c++;
        }
        n--;
        if (k < m)
        {
            for (i = n-1; i >= l; i--)
            {
                v[m-1][i] = c;
                c++;
            }
            m--;
        }
        if (l < n)
        {
            for (i = m-1; i >= k; i--)
            {
                v[i][l] = c;
                c++;
            }
            l++;
        }
    }
    return v;
}

int main(){

}