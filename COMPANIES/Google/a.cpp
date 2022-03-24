#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int m , int n , int k){
    int lo = 0 , hi = m*n;
    while (lo < hi)
    {
        int mid = (lo + hi)/2;
        int count = 0;
        for (int i = 1; i <= m; i++)
        {
            count += n < mid/i ? n : mid/i;
        }
        if (count >= k)
        {
            hi = mid;
        }
        else
        {
            lo = mid+1;
        }
    }
    return lo;
}

int main(){
    // vector<int> v;
    // priority_queue<int> pq;
    int m = 9895, n = 28405;
    int k = 100787757;
    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         pq.push(i*j);
    //         if (pq.size() > k)
    //         {
    //             pq.pop();
    //         }
    //     }
    // }
    // sort(v.begin() , v.end());
    cout<<solve(m , n , k)<<endl;
}