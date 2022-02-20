#include<bits/stdc++.h>
using namespace std;

vector<int> lsidingmax(vector<int> A , int k){
    int n = A.size();
    vector<int> v(n);
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() == i-k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && A[dq.back()] < A[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k-1)
        {
            v.push_back(A[dq.front()]);
        }
    }
    return v;
}

int main(){

}