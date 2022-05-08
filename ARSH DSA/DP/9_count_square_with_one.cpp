#include<bits/stdc++.h>
using namespace std;

int countsquare(vector<vector<int>> &matrix){
    int res = 0;
    int n = matrix.size() , m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] && i && j)
            {
                matrix[i][j] += min({matrix[i-1][j] , matrix[i][j-1] , matrix[i-1][j-1]});
            }
            res += matrix[i][j];
        }
    }
    return res;
}

int main(){

}