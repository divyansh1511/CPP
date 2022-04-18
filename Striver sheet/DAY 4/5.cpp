#include<bits/stdc++.h>
using namespace std;

int subarrxor(int arr[] , int n , int b){
    map<int , int> mp;
    int ans = 0 , xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr ^= arr[i];
        int tmp = xorr ^ b;
        ans += mp[tmp];
        if (xorr == b)
        {
            ans++;
        }
        mp[xorr]++;
    }
    return ans;
}

int main(){

}