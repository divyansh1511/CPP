#include<bits/stdc++.h>
using namespace std;

int candy(vector<int> &A){
    int n = A.size();
    if (n <= 1)
    {
        return n;
    }
    vector<int> v(n , 1);
    for (int i = 1; i < n; i++)
    {
        if (A[i] > A[i-1])
        {
            v[i] = v[i-1]+1;
        }
    }
    for (int i = n-1; i > 0; i--)
    {
        if (A[i-1] > A[i])
        {
            v[i-1] = max(v[i-1] , v[i]+1);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += v[i];
    }
    return res;
}

int main(){

}