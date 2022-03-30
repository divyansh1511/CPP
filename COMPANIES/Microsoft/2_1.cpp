#include<bits/stdc++.h>
using namespace std;

int grid_unique_path(int a , int b){
    vector<vector<int>> v(a , vector<int>(b));
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            v[i][j] = v[i-1][j] + v[i][j-1];
        }
    }
    return v[a-1][b-1];
}

int main(){
    
}