#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonal(vector<vector<int> > &A) {
    int n = A.size();
    int N = 2*(n-1) + 1;
    vector<vector<int>> ans(N);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++){
            ans[i+j].push_back(A[i][j]);
        }
    }
    return ans;
}

int main(){

}