#include<bits/stdc++.h>
using namespace std;

int majorityele(vector<int> v){
    unordered_map<int , int> mp;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
    }
    int ans = 0;
    int a = 0;
    for(auto it : mp){
        if (it.second > floor(n/2))
        {
            int b = max(a , it.second);
            if (a < b)
            {
                ans = it.first;
                a = b;
            }
        }   
    }
    return ans;
}

int majorityeleopti(vector<int> v){
    int n = v.size();
    int ans = 0;
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        if (val == 0)
        {
            ans = v[i];
        }
        if (ans == v[i])
        {
            val++;
        }
        else
        {
            val--;
        }
    }
    return ans;
}

int main(){

}