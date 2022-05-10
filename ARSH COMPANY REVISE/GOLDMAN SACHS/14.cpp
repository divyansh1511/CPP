#include<bits/stdc++.h>
using namespace std;

int minsubarr(int s , vector<int> v){
    int l = 0, r = 0 , n = v.size() , sum = 0 , len = INT_MAX;
    while (r < n)
    {
        sum += v[r++];
        while (sum >= s)
        {
            len = min(len , r-l);
            sum -= v[l++];
        }
    }
    return len == INT_MAX ? 0 : len;
}

int main(){

}