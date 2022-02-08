#include<bits/stdc++.h>
using namespace std;

int perfect_peak(vector<int> A){
    int n = A.size();
    int left[n];
    int right[n];
    left[0] = A[0];
    right[n-1] = A[n-1];
    for(int i=1;i<n;i++){
        left[i] = max(left[i-1] , A[i]);
    }
    for(int i=n-2;i>=0;i--){
        right[i] = min(right[i+1] , A[i]);
    }
    for(int i=1;i<n-1;i++){
        if(left[i-1] < A[i] && right[i+1] > A[i]){
            return 1;
        }
    }
    return 0;
}

int main(){
    
}