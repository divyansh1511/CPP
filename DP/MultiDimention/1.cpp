#include<bits/stdc++.h>
using namespace std;

int minitotal(vector<vector<int>>&triangles){
    vector<int> mini = triangles[triangles.size() - 1];
    for (int i = triangles.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            mini[j] = min(mini[j] , mini[j+1]) + triangles[i][j];
        }
    }
    return mini[0];
}

int main(){

}