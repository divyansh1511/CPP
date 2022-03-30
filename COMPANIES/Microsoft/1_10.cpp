#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> antidiagonals(vector<vector<int>> v){
    int n = v.size();
    vector<vector<int>> ans;
    int b = 2*(n-1);
    for (int k = 0; k <= b; k++)
    {
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i+j == k)
                {
                    a.push_back(v[i][j]);
                }
            }
        }
        ans.push_back(a);
    }
    return ans;
}

int main(){
    
}