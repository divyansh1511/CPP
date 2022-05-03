#include<bits/stdc++.h>
using namespace std;

vector<int> twosum(vector<int> arr , int n , int target){
    unordered_map<int , int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(target - arr[i]) != mp.end())
        {
            return {mp[target-arr[i]] , i};
        }
        mp[arr[i]] = i;
    }
    return {};
}

int main(){

}