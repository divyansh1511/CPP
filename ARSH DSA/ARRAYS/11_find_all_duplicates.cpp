#include<bits/stdc++.h>
using namespace std;

vector<int> findDuplicate(int arr[] , int n){
    unordered_map<int , int> mp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] > 1)
        {
            v.push_back(mp[arr[i]]);
        }
    }
    return v;
}

int main(){

}