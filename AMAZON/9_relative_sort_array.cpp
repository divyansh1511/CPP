#include <bits/stdc++.h>
using namespace std;

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    map<int, int> mp;
    for (int i = 0; i < arr1.size(); i++)
    {
        mp[arr1[i]]++;
    }
    vector<int> ans;
    for (int i = 0; i < arr2.size(); i++)
    {
        int n = mp[arr2[i]];
        int a = arr2[i];
        while (n > 0)
        {
            ans.push_back(a);
            n--;
            mp[arr2[i]]--;
        }
    }
    for (auto it : mp)
    {
        while (it.second > 0)
        {
            ans.push_back(it.first);
            it.second--;
        }
    }
    return ans;
}

int main()
{
    
}