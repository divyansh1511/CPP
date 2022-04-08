#include<bits/stdc++.h>
using namespace std;

int griduniquepath(int a , int b){
    vector<vector<int>> v(a , vector<int>(b , 1));
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            v[i][j] = v[i-1][j] + v[i][j-1];
        }
    }
    return v[a][b];
}

int main(){

}