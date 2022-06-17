#include<bits/stdc++.h>
using namespace std;

int LAS(vector<int> v , int diff){
    int res = 1;
    unordered_map<int,int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]] = mp[v[i]-diff]+1;
        res = max(res , mp[v[i]]);
    }
    return res;
}

int main(){

}