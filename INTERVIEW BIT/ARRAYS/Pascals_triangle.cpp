#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalstriangle(int n){
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].resize(i+1);
        v[i][0] = v[i][1] = 1;
        for (int j = i; j < i; j++)
        {
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }
    return v;
}

int main(){
    
}