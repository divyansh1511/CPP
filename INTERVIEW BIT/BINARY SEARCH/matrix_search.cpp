#include<bits/stdc++.h>
using namespace std;

int searchMatrix(vector<vector<int> > &A, int B) {
    int N=A.size();
    int M=A[0].size();
    int start=0, end=N*M-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        int x=mid/M;
        int y=mid%M;
        if(A[x][y]==B) return 1;
        if(B<A[x][y]) end=mid-1;
        else start=mid+1;
    }
    return 0;
}

int main(){

}