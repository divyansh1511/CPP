#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> > &A) {
    int n = A.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(A[i][j] , A[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(A[i].begin() , A[i].end());
    }
}

int main(){

}