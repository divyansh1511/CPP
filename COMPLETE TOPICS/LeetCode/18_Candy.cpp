#include<bits/stdc++.h>
using namespace std;

int candy(int arr[] , int n){
    if (n <= 1)
    {
        return n;
    }
    vector<int> v(n , 1);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i-1])
        {
            v[i] = v[i-1]+1;
        }
    }
    for (int i = n-1; i > 0; i--)
    {
        if (arr[i-1] > arr[i])
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