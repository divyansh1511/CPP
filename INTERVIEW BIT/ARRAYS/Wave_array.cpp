#include<bits/stdc++.h>
using namespace std;

vector<int> wave(vector<int> &A) {
    int n =A.size();
    sort(A.begin() , A.end());
    for(int i=0;i<n;i+=2){
        if(i == n-1){
            break;
        }
        swap(A[i] , A[i+1]);
    }
    return A;
}

int main(){

}