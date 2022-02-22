#include<bits/stdc++.h>
using namespace std;

int longestsubarr(int arr[] , int n){
    unordered_map<int , int> mp;
    int sum = 0 , maxelen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (arr[i] == 0) ? -1 : 1;
        if (sum == 1)
        {
            maxelen = i+1;
        }
        else if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
        if (mp.find(sum - 1) != mp.end())
        {
            maxelen = max(maxelen , i - mp[sum-1]);
        }
    }
    return maxelen;
}

int main(){
    int arr[] = {1,0,1,0,1,0};
    cout<<longestsubarr(arr , 6)<<endl;
}