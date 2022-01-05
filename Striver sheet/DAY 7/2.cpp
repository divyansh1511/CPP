#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threesum(vector<int> v){
    sort(v.begin() , v.end());
    int n = v.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && v[i] == v[i-1])
        {
            continue;
        }
        int l = i+1 , r = n-1;
        while (l < r)
        {
            int sum = v[i] + v[l] + v[r];
            if (sum < 0)
            {
                l++;
            }
            else if (sum > 0)
            {
                r--;
            }
            else
            {
                ans.push_back({v[i] , v[l] , v[r]});
                while ((l+1 < r) && (v[l] = v[l+1]))
                {
                    l++;
                }
                while ((l<r) && (v[r] == v[r-1]))
                {
                    r++;
                }
                l++;
                r--;
            }
        }
    }
    return ans;
}

int main(){
    
}