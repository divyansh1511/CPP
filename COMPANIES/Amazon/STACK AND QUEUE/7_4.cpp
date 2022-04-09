#include<bits/stdc++.h>
using namespace std;

vector<int> slidingwindow(vector<int> A , int B){
    int n = A.size();
    deque<int> dq;
    vector<int> v;
    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front() == i-B){
            dq.pop_front();
        }
        while(!dq.empty() && A[dq.back()] < A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= B-1){
            v.push_back(A[dq.front()]);
        }
    }
    return v;
}

int main(){

}