#include<bits/stdc++.h>
using namespace std;

int minpathsum(vector<vector<int>> v){
    vector<int> mini = v[v.size() - 1];
    for (int i = v.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            mini[j] = v[i][j] + min(mini[j] , mini[j+1]);
        }
    }
    return mini[0];
}

int main(){

}