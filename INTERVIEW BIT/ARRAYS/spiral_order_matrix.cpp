#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> spiralorder(int A){
    vector<vector<int>> a(A , vector<int>(A));
    int i, k = 0, l = 0;
    int c = 1;
    int m = A , n = A;
    while (k < m && l < n) {
        for (i = l; i < n; ++i) {
            a[k][i] = c;
            c++;
        }
        k++;
        for (i = k; i < m; ++i) {
            a[i][n-1] = c;
            c++;
        }
        n--;

        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                a[m-1][i] = c;
                c++;
            }
            m--;
        }

        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                a[i][l] = c;
                c++;
            }
            l++;
        }
    }
    return a;
}

int main(){

}