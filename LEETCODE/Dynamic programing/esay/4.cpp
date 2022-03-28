#include<bits/stdc++.h>
using namespace std;

void pascaltri(int n){
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].resize(i+1);
        v[i][0] = v[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[0].size();
    //     for (int j = 0; j < v[0].size(); j++)
    //     {
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}

int main(){
    pascaltri(5);
}